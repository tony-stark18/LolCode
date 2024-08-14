//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void topologicalSort(int node, vector<vector<pair<int,int>>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for(auto it : adj[node]) {
            if(!visited[it.first]) {
                topologicalSort(it.first, adj, visited, st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(N);
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }

        vector<bool> visited(N, false);
        stack<int> st;

        for(int i = 0; i < N; i++) {
            if(!visited[i]) {
                topologicalSort(i, adj, visited, st);
            }
        }

        vector<int> dist(N, 1e9);
        dist[0] = 0;

        while(!st.empty()) {
            int node = st.top();
            // cout<<node<<" ";
            st.pop();

            if(dist[node] != 1e9) {
                for(auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if(dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        for(int i = 0; i < N; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }
        // cout<<endl;
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends