#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        // Initialize the queue with all land cells
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        // If there are no land cells or all cells are land, return -1
        if (q.empty() || q.size() == m * n) return -1;

        int maxDist = -1;
        vector<int> directions = {-1, 0, 1, 0, -1};

        // Perform BFS
        while (!q.empty()) {
            int size = q.size();
            ++maxDist;

            for (int i = 0; i < size; ++i) {
                auto [x, y] = q.front();
                q.pop();

                for (int d = 0; d < 4; ++d) {
                    int nx = x + directions[d];
                    int ny = y + directions[d + 1];

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1; // Mark as visited
                        q.push({nx, ny});
                    }
                }
            }
        }

        return maxDist;
    }
};
