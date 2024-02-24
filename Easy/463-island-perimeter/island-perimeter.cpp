class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>> &vis,int row,int col,int m,int n,int delrow[],int delcol[],int &perimeter){
        vis[row][col] = 1;
        int cnt = 4;
        for(int i=0; i<4; i++){
            int nr = row + delrow[i];
            int nc = col + delcol[i];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                cnt--;
                if(!vis[nr][nc]){
                    dfs(grid, vis, nr, nc, m, n, delrow, delcol, perimeter);
                }
            }
        }
        perimeter += cnt;

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int perimeter = 0;
        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    dfs(grid,vis,i,j,m,n,delrow,delcol,perimeter);
                    break;
                }
            }
        }
        return perimeter;
    }
};