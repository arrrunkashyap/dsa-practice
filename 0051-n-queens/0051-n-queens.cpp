class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;

    unordered_set<int> col;
    unordered_set<int> diag1;   // row - col
    unordered_set<int> diag2;   // row + col

    void backtrack(int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col.count(c) ||
                diag1.count(row - c) ||
                diag2.count(row + c))
                continue;

            board[row][c] = 'Q';
            col.insert(c);
            diag1.insert(row - c);
            diag2.insert(row + c);

            backtrack(row + 1, n);

            board[row][c] = '.';
            col.erase(c);
            diag1.erase(row - c);
            diag2.erase(row + c);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        backtrack(0, n);
        return ans;
    }
};