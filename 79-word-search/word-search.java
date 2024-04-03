class Solution {
    public boolean soln(char[][] board, String word, int r, int c, int ind, int m, int n){
        if(ind == word.length()) return true;
        if(r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word.charAt(ind)) return false;
        
        char temp = board[r][c]; // Store the original character
        board[r][c] = '#'; // Mark the current character as visited
        
        // Check in all four directions
        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};
        for(int i = 0; i < 4; i++){
            int newr = r + dr[i];
            int newc = c + dc[i];
            if(soln(board, word, newr, newc, ind + 1, m, n)) return true;
        }
        
        board[r][c] = temp; // Revert back to the original character
        return false;
    }
    
    public boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word.charAt(0) && soln(board, word, i, j, 0, m, n)) return true;
            }
        }
        return false;
    }
}
