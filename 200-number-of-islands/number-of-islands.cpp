class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int r, int c, int m, int n) {
        vis[r][c] = 1;
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (int k = 0; k < 4; ++k) {
            int nr = r + directions[k][0];
            int nc = c + directions[k][1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == '1') {
                dfs(grid, vis, nr, nc, m, n);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int cnt =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    cnt++;
                    dfs(grid,vis,i,j,m,n);
                }
            }
        }
        return cnt;
    }
};