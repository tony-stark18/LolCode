class Solution {
private:
    bool dfs(int node, vector<vector<int>> &adj,vector<int> &vis,vector<int> &pvis){
        vis[node] = 1;
        pvis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pvis)) return true;
            }
            else if(pvis[it]==1){
                return true;
            }
        }
        pvis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int> vis(numCourses,0);
        vector<int> pvis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pvis)) return false;
            }
        }
        return true;
    }
};