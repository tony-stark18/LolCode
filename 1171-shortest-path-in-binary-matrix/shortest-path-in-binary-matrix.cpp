class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid, int n,
            vector<vector<int>>& vis) {
        if (r == n - 1 && c == n - 1)
            return 1;
        vis[r][c] = 1;
        int minDist = 1e9;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nr = r + i;
                int nc = c + j;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc] &&
                    grid[nr][nc] == 0) {
                    int dst = dfs(nr, nc, grid, n, vis);
                    minDist = min(minDist, dst);
                }
            }
        }
        vis[r][c] = 0;
        return minDist + 1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1])
            return -1;
        // // int n = grid[0].size();
        // int ans = dfs(0, 0, grid, n, vis);
        // if(ans>=1e9) return -1;
        // return ans;
        vector<vector<int>> distance(n, vector<int>(n, 1e9));
        distance[0][0]=0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    int nr = row + i;
                    int nc = col + j;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 0 && distance[nr][nc] > 1 + dist) {
                        distance[nr][nc] = 1 + dist;
                        pq.push({1 + dist, {nr, nc}});
                    }
                }
            }
        }
        if(distance[n-1][n-1]>=1e9) return -1;
        return distance[n - 1][n - 1]+1;
        // return -1;
    }
};