class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;

        for (int card : deck)
            freq[card]++;

        int g = 0;

        for (auto &it : freq)
            g = gcd(g, it.second);

        return g >= 2;
    }

    int gcd(int a, int b) {
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};