class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre,
                                     vector<vector<int>>& q) {
        vector<bool> ans(q.size(), false);
        if (pre.size() == 0)
            return ans;
        vector<vector<int>> adj(n);
        for (auto it : pre) {
            adj[it[0]].push_back(it[1]);
        }
        vector<vector<int>> canReach(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            queue<int> q;
            vector<int> vis(n,0);
            vis[i]=1;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it:adj[node]){
                    canReach[i][it]=1;
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
        }
        for(int i=0;i<q.size();i++){
            int u = q[i][0];
            int v = q[i][1];
            if(canReach[u][v]) ans[i]=true;
        }
        return ans;
    }
};