class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        int k = 0;
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], succProb[k]});
            adj[it[1]].push_back({it[0], succProb[k]});
            k++;
        }
        
        priority_queue<pair<double, int>> pq;
        vector<double> probability(n, 0.0);  // Initialize with 0.0
        probability[start_node] = 1.0;
        pq.push({1.0, start_node});
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            double prob = it.first;
            int node = it.second;
            
            if (node == end_node) {
                return prob;
            }
            
            for (auto& neighbor : adj[node]) {
                int next_node = neighbor.first;
                double edge_prob = neighbor.second;
                
                if (prob * edge_prob > probability[next_node]) {
                    probability[next_node] = prob * edge_prob;
                    pq.push({probability[next_node], next_node});
                }
            }
        }
        
        return 0.0;  // If no path exists, return 0.0
    }
};
