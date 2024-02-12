class Solution {
private:
    bool dfs(int start, vector<vector<int>>& adj, vector<int> &vis,vector<int> &pvis){
        vis[start] = 1;
        pvis[start] = 1;
        for(auto it:adj[start]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pvis)) return true;
            }
            else if(pvis[it]) return true;
        }
        pvis[start] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> pvis(n,0);
        vector<int> safeNodes;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pvis);
            }
        }
        for(int i=0;i<n;i++){
            if(pvis[i]==0){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};