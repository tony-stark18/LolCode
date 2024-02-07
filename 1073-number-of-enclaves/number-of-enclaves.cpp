class Solution {
private:
    void dfs(vector<vector<int>> &vis,vector<vector<int>>& board,int dr[],int dc[],int r,int c,int n,int m){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]==1){
                dfs(vis,board,dr,dc,nr,nc,n,m);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 1 && !vis[i][j]) {
                        dfs(vis, board, dr, dc, i, j, n, m);
                    }
                }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};