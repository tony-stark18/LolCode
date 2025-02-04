class Solution {
public:
    int time = 0;
    void dfs(vector<vector<int>> &adj,vector<int> &vis,vector<int> &ToI,vector<int> &LToI,int node,int parent,vector<vector<int>> &bridges){
        vis[node]=1;
        ToI[node]=LToI[node]=time;
        time++;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(adj,vis,ToI,LToI,it,node,bridges);
                if(LToI[it]>ToI[node]){
                    bridges.push_back({it,node});
                } else{
                    LToI[node]=min(LToI[node],LToI[it]);
                }
            } else{
                LToI[node]=min(LToI[node],LToI[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        vector<int> ToI(n);
        vector<int> LToI(n);
        vector<vector<int>> ans;
        dfs(adj,vis,ToI,LToI,0,-1,ans);
        return ans;
    }
};