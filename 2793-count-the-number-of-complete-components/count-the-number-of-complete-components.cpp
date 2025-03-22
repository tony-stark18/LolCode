class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUltParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUltParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUltParent(u);
        int ulp_v = findUltParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        vector<vector<int>> adj(n);
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            ds.unionBySize(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; i++) {
            components[ds.findUltParent(i)].push_back(i);
        }
        
        int completeCount = 0;
        for (auto& [root, nodes] : components) {
            bool isComplete = true;
            int size = nodes.size();
            for (int node : nodes) {
                if (adj[node].size() != size - 1) {
                    isComplete = false;
                    break;
                }
            }
            if (isComplete) completeCount++;
        }
        
        return completeCount;
    }
};