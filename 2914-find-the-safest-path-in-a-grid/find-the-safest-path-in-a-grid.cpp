int IO = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> compute_min_safe_factors(vector<pair<int, int>>& thieves, int n) {
        vector<vector<int>> min_safe_factors(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Initialize safeness factors for thief positions
        for (auto& thief : thieves) {
            int r = thief.first, c = thief.second;
            min_safe_factors[r][c] = 0;
            q.push({r, c});
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Perform multi-source BFS to calculate safeness factors
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
                    if (min_safe_factors[nr][nc] > min_safe_factors[r][c] + 1) {
                        min_safe_factors[nr][nc] = min_safe_factors[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return min_safe_factors;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1]) return 0;

        vector<pair<int, int>> thieves;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    thieves.push_back({i, j});
                }
            }
        }

        // Precompute safeness factors for all cells
        vector<vector<int>> min_safe_factors = compute_min_safe_factors(thieves, n);

        // Priority queue to maximize safeness factor along the path
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({min_safe_factors[0][0], {0, 0}});

        vector<vector<int>> factors(n, vector<int>(n, INT_MIN));
        factors[0][0] = min_safe_factors[0][0];

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int factor = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n - 1 && c == n - 1) return factor;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n) {
                    int new_factor = min(factor, min_safe_factors[nr][nc]);
                    if (new_factor > factors[nr][nc]) {
                        pq.push({new_factor, {nr, nc}});
                        factors[nr][nc] = new_factor;
                    }
                }
            }
        }

        return 0;
    }
};
