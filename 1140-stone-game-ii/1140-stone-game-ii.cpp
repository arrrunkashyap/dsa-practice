class Solution {
public:
    int n;
    vector<int> suffix;
    int memo[101][101];

    int dfs(int i, int M) {
        if (i >= n) return 0;

        if (2 * M >= n - i)
            return suffix[i];

        if (memo[i][M] != -1)
            return memo[i][M];

        int ans = 0;

        for (int X = 1; X <= 2 * M; X++) {
            ans = max(ans,
                      suffix[i] - dfs(i + X, max(M, X)));
        }

        return memo[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.assign(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        memset(memo, -1, sizeof(memo));

        return dfs(0, 1);
    }
};