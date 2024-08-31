class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            auto it = edges[i];
            adj[it[0]].push_back({it[1],succProb[i]});
            adj[it[1]].push_back({it[0],succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});
        vector<double> probability(n,0.0);
        probability[start_node]=1.0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            double prob = it.first;
            int node = it.second;
            if(node==end_node) return prob;

            for(auto it:adj[node]){
            int adj_node = it.first;
                double edge_prob = it.second;

                if(prob*edge_prob>probability[adj_node]){
                    probability[adj_node] = prob*edge_prob;
                    pq.push({probability[adj_node],adj_node});
                }
            }
        }
        return 0;
    }
};  