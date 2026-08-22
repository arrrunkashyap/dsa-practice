class Solution {
public:
    vector<string> ans;
    vector<string> path;

    void backtrack(string &s, int index) {
        // Exactly 4 parts
        if (path.size() == 4) {
            if (index == s.size()) {
                ans.push_back(
                    path[0] + "." +
                    path[1] + "." +
                    path[2] + "." +
                    path[3]
                );
            }
            return;
        }
        for (int len = 1; len <= 3; len++) {

            if (index + len > s.size())
                break;

            if (len > 1 && s[index] == '0')
                break;

            string part = s.substr(index, len);
            if (stoi(part) > 255)
                break;
            path.push_back(part);
            backtrack(s, index + len);
            path.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0);
        return ans;
    }
};