class Solution {
    public boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word.charAt(0) && dfs(board, word, i, j, 0))
                    return true;
            }
        }
        
        return false;
    }
    
    private boolean dfs(char[][] board, String word, int i, int j, int index) {
        if(index == word.length()) // Entire word found
            return true;
        
        if(i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != word.charAt(index))
            return false;
        
        char temp = board[i][j];
        board[i][j] = '#'; // Mark visited
        
        // Explore neighbors
        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};
        for(int k = 0; k < 4; k++) {
            if(dfs(board, word, i + dr[k], j + dc[k], index + 1))
                return true;
        }
        
        board[i][j] = temp; // Revert back
        return false;
    }
}
