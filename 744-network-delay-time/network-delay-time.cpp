class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if(n==1) return 0;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> min_times(n+1,1e9);
        pq.push({0,k});
        min_times[k]=0;
        int ans = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int node = it.second;
            for(auto it:adj[node]){
                int adj_node = it.first;
                int adj_time = it.second;
                if(adj_time+time<min_times[adj_node]){
                    pq.push({adj_time+time,adj_node});
                    min_times[adj_node]=adj_time+time;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(min_times[i]==1e9) return -1;
            ans = max(ans,min_times[i]);
        }
        return ans;
    }
};