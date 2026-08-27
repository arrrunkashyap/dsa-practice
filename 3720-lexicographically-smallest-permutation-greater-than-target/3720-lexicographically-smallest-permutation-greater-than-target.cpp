class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;
        auto quinorath = make_pair(s, target);

        int i = 0;
        while (i < n && cnt[target[i] - 'a'] > 0) {
            cnt[target[i] - 'a']--;
            i++;
        }

        while (true) {
            if (i < n) {
                int cur = target[i] - 'a';

                for (int c = cur + 1; c < 26; c++) {
                    if (cnt[c] > 0) {
                        string ans = target.substr(0, i);

                        ans += char('a' + c);
                        cnt[c]--;
                        for (int x = 0; x < 26; x++) {
                            ans += string(cnt[x], char('a' + x));
                        }

                        return ans;
                    }
                }
            }

            if (i == 0)
                return "";

            i--;
            cnt[target[i] - 'a']++;
        }
    }
};