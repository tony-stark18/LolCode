//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[],vector<int> &vis,vector<int> &pvis,int node){
        vis[node]=1;
        pvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(adj,vis,pvis,it)) return true;
            }
            else if(pvis[it]==1) return true;
        }
        pvis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> pvis(V,0);
        for(int i=0;i<V;i++){
            if(dfs(adj,vis,pvis,i)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends