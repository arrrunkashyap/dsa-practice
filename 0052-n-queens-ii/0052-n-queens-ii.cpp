class Solution {
public:
    int count = 0;

    unordered_set<int> col;
    unordered_set<int> diag1;   // row - col
    unordered_set<int> diag2;   // row + col

    void backtrack(int row, int n) {
        if (row == n) {
            count++;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col.count(c) || diag1.count(row - c) || diag2.count(row + c))
                continue;

            col.insert(c);
            diag1.insert(row - c);
            diag2.insert(row + c);

            backtrack(row + 1, n);

            col.erase(c);
            diag1.erase(row - c);
            diag2.erase(row + c);
        }
    }

    int totalNQueens(int n) {
        backtrack(0, n);
        return count;
    }
};