class Solution {
    public boolean soln(char[][] board, String word,int r,int c,int ind,int[][] vis,int dr[],int dc[],int m,int n){
        if(ind == word.length()) return true;
        if(r < 0 || r >= m || c < 0 || c >= n || vis[r][c] == 1 || board[r][c] != word.charAt(ind)) return false;
        
        vis[r][c] = 1;
        for(int i = 0; i < 4; i++){
            int newr = r + dr[i];
            int newc = c + dc[i];
            if(soln(board, word, newr, newc, ind + 1, vis, dr, dc, m, n)) return true;
        }
        vis[r][c] = 0;
        return false;
    }
    
    public boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length;
        int[][] vis = new int[m][n];
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word.charAt(0) && soln(board, word, i, j, 0, vis, dr, dc, m, n)) return true;
            }
        }
        return false;
    }
}
