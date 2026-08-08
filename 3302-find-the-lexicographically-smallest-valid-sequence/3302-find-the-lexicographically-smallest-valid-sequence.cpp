class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> suf(n + 1, m);

        int j = m;

        for (int i = n - 1; i >= 0; --i) {
            if (j > 0 && word1[i] == word2[j - 1]) {
                --j;
            }

            suf[i] = j;
        }

        vector<int> ans;

        int pos = 0;
        bool usedMismatch = false;

        for (int k = 0; k < m; ++k) {

            while (pos < n) {

                // Case 1: Exact match
                if (word1[pos] == word2[k]) {
                    ans.push_back(pos);
                    ++pos;
                    break;
                }


                if (!usedMismatch && suf[pos + 1] <= k + 1) {
                    ans.push_back(pos);
                    ++pos;
                    usedMismatch = true;
                    break;
                }

                ++pos;
            }

            // Not enough indices to construct word2.
            if ((int)ans.size() != k + 1) {
                return {};
            }
        }

        return ans;
    }
};