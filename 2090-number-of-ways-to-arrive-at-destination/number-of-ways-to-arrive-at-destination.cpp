class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        vector<long long int> times(n,LLONG_MAX);
        vector<int> ways(n,0);
        times[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long int time = it.first;
            int node = it.second;
            for(auto it:adj[node]){
                int adj_node = it.first;
                long long int edge_time = it.second;
                if(time+edge_time==times[adj_node]){
                    ways[adj_node]=((long)ways[adj_node]+(long)ways[node])%mod;
                } else if(time+edge_time<times[adj_node]){
                    pq.push({time+edge_time,adj_node});
                    times[adj_node] = time+edge_time;
                    ways[adj_node]=(ways[node])%mod;
                }
            } 
        }
        return (ways[n-1])%mod;
    }
};