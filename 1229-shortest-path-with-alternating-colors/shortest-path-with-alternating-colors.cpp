class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //0-red,1-blue
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:redEdges){
            adj[it[0]].push_back({it[1],0});
        }
        for(auto it:blueEdges){
            adj[it[0]].push_back({it[1],1});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> distances(n,1e9);
        vector<vector<int>> colors(2,vector<int>(n,0));
        // vector<int> blue(n,0);
        // vector<int> red(n,0);
        distances[0]=0;
        q.push({0,{0,-1}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dist = it.first;
            int node = it.second.first;
            int prevCol = it.second.second;
            if(prevCol!=-1){
                colors[prevCol][node]++;
            }
            for(auto it:adj[node]){
                int adjNode = it.first;
                int currCol = it.second;
                if(prevCol!=currCol && !colors[currCol][adjNode]){
                    q.push({dist+1,{adjNode,currCol}});
                    colors[currCol][adjNode]++;
                    distances[adjNode]=min(distances[adjNode],dist+1);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(distances[i]==1e9) distances[i]=-1;
        }
        return distances;
    }

};