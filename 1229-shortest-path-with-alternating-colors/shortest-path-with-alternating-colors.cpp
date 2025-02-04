#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : redEdges) {
            adj[edge[0]].push_back({edge[1], 0});
        }
        for (auto& edge : blueEdges) {
            adj[edge[0]].push_back({edge[1], 1});
        }

        queue<pair<int, int>> q;
        vector<vector<int>> distances(2, vector<int>(n, 1e9));

        distances[0][0] = distances[1][0] = 0;
        q.push({0, 0}); 
        q.push({0, 1});

        while (!q.empty()) {
            auto [node, prevColor] = q.front();
            q.pop();

            for (auto& [nextNode, edgeColor] : adj[node]) {
                if (edgeColor != prevColor && distances[edgeColor][nextNode] == 1e9) {
                    distances[edgeColor][nextNode] = distances[prevColor][node] + 1;
                    q.push({nextNode, edgeColor});
                }
            }
        }

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int shortest = min(distances[0][i], distances[1][i]);
            result[i] = (shortest == 1e9) ? -1 : shortest;
        }
        return result;
    }
};
