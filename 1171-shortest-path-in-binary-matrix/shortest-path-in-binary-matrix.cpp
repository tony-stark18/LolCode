class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        vector<vector<int>> gScore(n, vector<int>(n, 1e9));
        gScore[0][0] = 1;  // Start from (0, 0), gScore is 1

        auto heuristic = [n](int r, int c) {
            return max(n - 1 - r, n - 1 - c);  // Manhattan distance
        };

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        pq.push({1 + heuristic(0, 0), {0, 0}});  // Push starting point with F-Score

        vector<pair<int, int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1},
            {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
        };

        while (!pq.empty()) {
            auto [fScore, pos] = pq.top();
            pq.pop();
            int row = pos.first, col = pos.second;

            // Early exit if we reach the bottom-right corner
            if (row == n - 1 && col == n - 1)
                return gScore[row][col];

            for (auto& dir : directions) {
                int nr = row + dir.first;
                int nc = col + dir.second;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    int tentative_gScore = gScore[row][col] + 1;
                    if (tentative_gScore < gScore[nr][nc]) {
                        gScore[nr][nc] = tentative_gScore;
                        int hScore = heuristic(nr, nc);
                        pq.push({tentative_gScore + hScore, {nr, nc}});
                    }
                }
            }
        }

        return -1;  // No path found
    }
};
