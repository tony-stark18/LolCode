class Solution {
public:
    bool soln(const vector<vector<int>>& grid, int r, int c, int n, const vector<vector<int>>& dir) {
        if (grid[r][c] == n * n - 1) return true;
        for (const auto& d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];
            int prev = grid[r][c];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == prev + 1) {
                if (soln(grid, nr, nc, n, dir)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false;
        static const vector<vector<int>> dir = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
        return soln(grid, 0, 0, grid.size(), dir);
    }
};