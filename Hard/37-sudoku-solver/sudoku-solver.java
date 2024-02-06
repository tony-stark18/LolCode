class Solution {
    public boolean isValid(char[][] board, int row, int col, char target) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == target) {
                return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == target) {
                return false;
            }
        }
        int subgridStartRow = 3 * (row / 3);
        int subgridStartCol = 3 * (col / 3);
        for (int i = subgridStartRow; i < subgridStartRow + 3; i++) {
            for (int j = subgridStartCol; j < subgridStartCol + 3; j++) {
                if (board[i][j] == target) {
                    return false;
                }
            }
        }
        return true;
    }

    public boolean solution(char[][] board, int col, int row) {
    if (col >= 9) {
        col = 0;
        row++;
    }
    if (row >= 9) {
        return true; // Indicates successful completion
    }
    if (board[row][col] == '.') {
        for (char c = '1'; c <= '9'; c++) {
            if (isValid(board, row, col, c)) {
                board[row][col] = c;
                if (solution(board, col + 1, row)) {
                    return true; // If the puzzle is solved, return true
                }
                board[row][col] = '.'; // Reset the value if the puzzle is not solved
            }
        }
        return false; // If no valid value is found, backtrack
    } else {
        return solution(board, col + 1, row); // Move to the next cell
    }
}

public void solveSudoku(char[][] board) {
    solution(board, 0, 0);
}


}