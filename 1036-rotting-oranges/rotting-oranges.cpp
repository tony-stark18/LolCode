class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int cntFresh = 0;
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else if (grid[i][j] == 1) {
                    cntFresh++;
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        int tm = 0;
        int cnt = 0;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(t, tm);
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                    vis[nr][nc] != 2 && grid[nr][nc] == 1) {
                    q.push({{nr, nc}, t + 1});
                    vis[nr][nc] = 2;
                    cnt++;
                }
            }
        }
        if (cnt != cntFresh)
            return -1;
        return tm;
    }
};