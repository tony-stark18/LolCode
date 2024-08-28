class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<int>> efforts(m, vector<int>(n, 1e9));
        pq.push({0, {0, 0}});
        efforts[0][0] = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if (row == m - 1 && col == n - 1)
                return effort;

            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newEffort =
                        max(abs(heights[row][col] - heights[nr][nc]), effort);
                    if (efforts[nr][nc] > newEffort) {
                        efforts[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};