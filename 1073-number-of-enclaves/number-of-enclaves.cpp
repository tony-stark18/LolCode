class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis,int dr[],int dc[],int m,int n){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,grid,vis,dr,dc,m,n);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for(int i=0;i<m;i++){
            if(board[i][0]==1){
                vis[i][0]=1;
                dfs(i,0,board,vis,dr,dc,m,n);
            }
            if(board[i][n-1]==1){
                vis[i][n-1]=1;
                dfs(i,n-1,board,vis,dr,dc,m,n);
            }
        }
        for(int j=0;j<n;j++){
            if(board[0][j]==1){
                vis[0][j]=1;
                dfs(0,j,board,vis,dr,dc,m,n);
            }
            if(board[m-1][j]==1){
                vis[m-1][j]=1;
                dfs(m-1,j,board,vis,dr,dc,m,n);
            }
        }
        int count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1 && !vis[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};