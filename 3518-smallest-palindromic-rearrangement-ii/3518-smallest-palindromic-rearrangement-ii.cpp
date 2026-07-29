class Solution {
public:
    const long long LIMIT = 1000001;

    long long nCr(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);
        long long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res >= LIMIT) return LIMIT;
        }
        return res;
    }

    long long countWays(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        long long ans = 1;
        int rem = total;

        for (int x : cnt) {
            if (x == 0) continue;
            ans *= nCr(rem, x);
            if (ans >= LIMIT) return LIMIT;
            rem -= x;
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half(26, 0);
        char mid = '\0';

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2) mid = char('a' + i);
        }

        if (countWays(half) < k)
            return "";

        int halfLen = s.size() / 2;
        string left = "";

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0) continue;

                half[c]--;
                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                } else {
                    k -= ways;
                    half[c]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
            return left + string(1, mid) + right;
        return left + right;
    }
};
