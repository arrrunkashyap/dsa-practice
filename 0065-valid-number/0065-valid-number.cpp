class Solution {
public:
    bool isNumber(string s) {

        int n = s.size();
        int i = 0;
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }
        bool digit = false;
        while (i < n && isdigit(s[i])) {
            digit = true;
            i++;
        }
        if (i < n && s[i] == '.') {
            i++;
            while (i < n && isdigit(s[i])) {
                digit = true;
                i++;
            }
        }
        if (!digit)
            return false;

      
        if (i < n && (s[i] == 'e' || s[i] == 'E')) {

            i++;
            if (i < n && (s[i] == '+' || s[i] == '-')) {
                i++;
            }
            bool exponentDigit = false;

            while (i < n && isdigit(s[i])) {
                exponentDigit = true;
                i++;
            }

            if (!exponentDigit)
                return false;
        }
        return i == n;
    }
};