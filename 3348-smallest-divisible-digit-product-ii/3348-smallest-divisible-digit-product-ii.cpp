class Solution {
private:
    int factor[10][4] = {
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2
        {0, 1, 0, 0}, // 3
        {2, 0, 0, 0}, // 4
        {0, 0, 1, 0}, // 5
        {1, 1, 0, 0}, // 6
        {0, 0, 0, 1}, // 7
        {3, 0, 0, 0}, // 8
        {0, 2, 0, 0}  // 9
    };


    array<int, 10> getDigits(array<int, 4> cnt) {
        array<int, 10> res{};

    
        res[8] = cnt[0] / 3;
        cnt[0] %= 3;

   
        res[9] = cnt[1] / 2;
        cnt[1] %= 2;


        res[4] = cnt[0] / 2;
        cnt[0] %= 2;

        if (cnt[0] == 1 && cnt[1] == 1) {
            res[6] = 1;
            cnt[0] = 0;
            cnt[1] = 0;
        }

        if (cnt[1] == 1 && res[4] == 1) {
            res[4] = 0;
            res[6] = 1;
            cnt[0] = 1;
            cnt[1] = 0;
        }

        res[2] = cnt[0];
        res[3] = cnt[1];

        res[5] = cnt[2];
        res[7] = cnt[3];

        return res;
    }

    int countDigits(const array<int, 10>& cnt) {
        int total = 0;

        for (int x : cnt)
            total += x;

        return total;
    }

    string build(const array<int, 10>& cnt) {
        string ans;

        for (int d = 2; d <= 9; d++) {
            ans += string(cnt[d], char('0' + d));
        }

        return ans;
    }

    bool enough(array<int, 4> need, int spaces) {
        int cnt = 0;

        auto digits = getDigits(need);

        for (int d = 2; d <= 9; d++)
            cnt += digits[d];

        return cnt <= spaces;
    }

public:
    string smallestNumber(string num, long long t) {
        array<int, 4> target{};

        int primes[] = {2, 3, 5, 7};

        for (int i = 0; i < 4; i++) {
            while (t % primes[i] == 0) {
                t /= primes[i];
                target[i]++;
            }
        }
        if (t != 1)
            return "-1";

        auto requiredDigits = getDigits(target);

        if (countDigits(requiredDigits) > (int)num.size()) {
            return build(requiredDigits);
        }

        array<int, 4> prefix{};

        for (char ch : num) {
            int d = ch - '0';

            for (int j = 0; j < 4; j++)
                prefix[j] += factor[d][j];
        }


        int firstZero = num.find('0');

        if (firstZero == string::npos) {

            firstZero = num.size();

            bool valid = true;

            for (int j = 0; j < 4; j++) {
                if (prefix[j] < target[j]) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                return num;
        }
        for (int i = (int)num.size() - 1; i >= 0; i--) {

            int current = num[i] - '0';
            for (int j = 0; j < 4; j++)
                prefix[j] -= factor[current][j];

            int spaces = num.size() - 1 - i;

         
            if (i > firstZero)
                continue;

            for (int bigger = current + 1; bigger <= 9; bigger++) {

                array<int, 4> need{};

                for (int j = 0; j < 4; j++) {

                    int already =
                        prefix[j] + factor[bigger][j];

                    need[j] = max(0, target[j] - already);
                }

                auto suffixDigits = getDigits(need);

                if (countDigits(suffixDigits) <= spaces) {

                    int ones =
                        spaces - countDigits(suffixDigits);

                    string ans = num.substr(0, i);
                    ans += char('0' + bigger);
                    ans += string(ones, '1');  
                    ans += build(suffixDigits);

                    return ans;
                }
            }
        }

        requiredDigits = getDigits(target);

        int used = countDigits(requiredDigits);

        return string(num.size() + 1 - used, '1')
             + build(requiredDigits);
    }
};