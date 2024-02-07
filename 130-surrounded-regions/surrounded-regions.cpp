class Solution {

private:
    void dfs(vector<vector<int>> &vis,vector<vector<char>>& board,int dr[],int dc[],int r,int c,int n,int m){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]=='O'){
                dfs(vis,board,dr,dc,nr,nc,n,m);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(vis,board,dr,dc,i,0,n,m);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(vis,board,dr,dc,i,m-1,n,m);
            }
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                dfs(vis,board,dr,dc,0,j,n,m);
            }
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                dfs(vis,board,dr,dc,n-1,j,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};