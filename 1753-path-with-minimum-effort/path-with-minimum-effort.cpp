int IO = []{
    ios::sync_with_stdio(false); cin.tie(nullptr); return 0;
}();
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        vector<vector<int>> difference(m, vector<int>(n, 1e9));
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // Track finalized cells

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        difference[0][0] = 0;

        while (!pq.empty()) {
            auto [curr_diff, cell] = pq.top();
            pq.pop();

            int r = cell.first, c = cell.second;

            // If already visited, skip
            if (visited[r][c]) continue;
            visited[r][c] = true;

            // If we've reached the bottom-right corner, return the answer
            if (r == m - 1 && c == n - 1) return curr_diff;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int new_diff = max(curr_diff, abs(heights[r][c] - heights[nr][nc]));
                    if (new_diff < difference[nr][nc]) {
                        difference[nr][nc] = new_diff;
                        pq.push({new_diff, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};
