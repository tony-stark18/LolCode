class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});
        
        vector<long long> times(n, LLONG_MAX);
        vector<int> ways(n, 0);
        
        times[0] = 0;
        ways[0] = 1;
        
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            
            if (time > times[node]) continue;
            
            for (auto& [adj_node, edge_time] : adj[node]) {
                if (time + edge_time == times[adj_node]) {
                    ways[adj_node] = (ways[adj_node] + ways[node]) % mod;
                } else if (time + edge_time < times[adj_node]) {
                    times[adj_node] = time + edge_time;
                    ways[adj_node] = ways[node];
                    pq.push({times[adj_node], adj_node});
                }
            }
        }
        
        return ways[n - 1];
    }
};
