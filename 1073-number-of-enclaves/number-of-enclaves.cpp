class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, int dr[], int dc[], int m, int n) {
        stack<pair<int, int>> stk;
        stk.push({r, c});
        grid[r][c] = 0;  // Mark as visited by setting it to 0
        
        while (!stk.empty()) {
            auto [cr, cc] = stk.top();
            stk.pop();
            
            for (int i = 0; i < 4; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 0;  // Mark as visited
                    stk.push({nr, nc});
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Perform DFS for all boundary cells with value 1
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1) {
                dfs(i, 0, grid, dr, dc, m, n);
            }
            if (grid[i][n - 1] == 1) {
                dfs(i, n - 1, grid, dr, dc, m, n);
            }
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1) {
                dfs(0, j, grid, dr, dc, m, n);
            }
            if (grid[m - 1][j] == 1) {
                dfs(m - 1, j, grid, dr, dc, m, n);
            }
        }

        // Count all remaining 1s in the grid
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};
