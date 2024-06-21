class Solution {
public:
    bool canPlace(vector<vector<char>>& board, char target, int r, int c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][c] == target)
                return false;
        }

        for (int i = 0; i < 9; i++) {
            if (board[r][i] == target)
                return false;
        }

        int row = (r / 3) * 3;
        int col = (c / 3) * 3;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (board[i][j] == target)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int r, int c) {
        if (r == 9) 
            return true;
        if (c == 9) 
            return solve(board, r + 1,0); 
        if (board[r][c] !='.')
            return solve(board, r, c + 1);
        for (char ch = '1'; ch <= '9'; ch++) {
            if (canPlace(board, ch, r, c)) {  
                board[r][c] = ch;           
                if (solve(board, r, c + 1))  
                    return true;
                board[r][c] = '.'; 
            }
        }
        return false; 
    }

    void solveSudoku(vector<vector<char>>& board) { solve(board, 0, 0); }
};