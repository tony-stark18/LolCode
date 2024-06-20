class Solution {
public:
    void soln(vector<vector<string>>& ans, vector<string>& board, vector<bool>& rows, vector<bool>& mainDiag, vector<bool>& antiDiag, int col, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (rows[i] || mainDiag[i - col + n - 1] || antiDiag[i + col])
                continue;
            // Place the queen
            board[i][col] = 'Q';
            rows[i] = mainDiag[i - col + n - 1] = antiDiag[i + col] = true;
            // Recur to place the rest
            soln(ans, board, rows, mainDiag, antiDiag, col + 1, n);
            // Remove the queen and backtrack
            board[i][col] = '.';
            rows[i] = mainDiag[i - col + n - 1] = antiDiag[i + col] = false;
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        vector<bool> rows(n, false);
        vector<bool> mainDiag(2 * n - 1, false); // main diagonal
        vector<bool> antiDiag(2 * n - 1, false); // anti-diagonal
        soln(ans, board, rows, mainDiag, antiDiag, 0, n);
        return ans;
    }
};
