class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<vector<int>> adj(n);
        for (auto& p : pre) {
            adj[p[0]].push_back(p[1]);
        }
        
        // Memoization table for reachability
        vector<vector<int>> memo(n, vector<int>(n, -1)); // -1: unvisited, 0: no, 1: yes

        // DFS to check reachability
        function<bool(int, int)> dfs = [&](int u, int v) {
            if (memo[u][v] != -1) return memo[u][v];
            for (int neighbor : adj[u]) {
                if (neighbor == v || dfs(neighbor, v)) {
                    return memo[u][v] = 1;
                }
            }
            return memo[u][v] = 0;
        };

        // Answer the queries
        vector<bool> ans;
        for (auto& query : q) {
            ans.push_back(dfs(query[0], query[1]));
        }
        return ans;
    }
};
