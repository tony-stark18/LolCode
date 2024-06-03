class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& board,vector<vector<int>>& vis,int dr[],int dc[],int m,int n){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && board[nr][nc]=='O'){
                dfs(nr,nc,board,vis,dr,dc,m,n);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                vis[i][0]=1;
                dfs(i,0,board,vis,dr,dc,m,n);
            }
            if(board[i][n-1]=='O'){
                vis[i][n-1]=1;
                dfs(i,n-1,board,vis,dr,dc,m,n);
            }
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                vis[0][j]=1;
                dfs(0,j,board,vis,dr,dc,m,n);
            }
            if(board[m-1][j]=='O'){
                vis[m-1][j]=1;
                dfs(m-1,j,board,vis,dr,dc,m,n);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
        
    }
};