class Solution {
public:
    bool is_valid(int r,int c,int m,int n){
        return r>=0 && r<m && c>=0 && c<n;
    }
    int dfs(vector<vector<int>>& grid,int r,int c,int dr[],int dc[],vector<vector<int>>& visited,int m,int n){
        visited[r][c]=1;
        int res = 1;
        for(int i=0;i<4;i++){
            int nr = dr[i]+r;
            int nc = dc[i]+c;
            if(is_valid(nr,nc,m,n) && !visited[nr][nc] && grid[nr][nc]){
                res+=dfs(grid,nr,nc,dr,dc,visited,m,n);
            }
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        vector<vector<int>> visited(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]){
                    int res = dfs(grid,i,j,dr,dc,visited,m,n);
                    ans = max(ans,res);
                }
            }
        }
        return ans;
    }
};