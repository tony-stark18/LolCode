class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> costs(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        costs[src] = 0;

        while(!q.empty()){
            auto i = q.front();
            q.pop();
            int stops = i.first;
            int node = i.second.first;
            int cost = i.second.second;

            if(stops>k) continue;
            for(auto it:adj[node]){
                int adjNode = it.first;
                int egdeW = it.second;

                if(egdeW+cost<costs[adjNode] && stops<=k){
                    costs[adjNode] = egdeW + cost;
                    q.push({stops+1,{adjNode,costs[adjNode]}});
                }
            }
        }
        if(costs[dst]==1e9) return -1;
        return costs[dst];
    }
};