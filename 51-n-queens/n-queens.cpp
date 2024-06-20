class Solution {
public:
    bool canPlace(vector<string>& board, int r, int c, int n) {
        // row
        int row = r;
        int col = c;
        while (col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }
        // col
        row = r;
        col = c;
        while (row >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
        }

        // diaog-1
        row = r;
        col = c;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        // diaog-2
        row = r;
        col = c;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void soln(vector<vector<string>>& ans, vector<string>& board, int col,
              int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (canPlace(board, i, col, n)) {
                board[i][col] = 'Q';
                soln(ans, board, col + 1, n);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        soln(ans, board, 0, n);
        return ans;
    }
};