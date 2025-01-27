class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
        size.resize(n + 1, 1);
    }

    int findUltParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUltParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUltParent(u);
        int ulp_v = findUltParent(v);

        if (ulp_u == ulp_v)
            return;

        int rank_ulp_u = rank[ulp_u];
        int rank_ulp_v = rank[ulp_v];

        if (rank_ulp_u > rank_ulp_v)
        {
            parent[ulp_v] = ulp_u;
        }
        else if (rank_ulp_v > rank_ulp_u)
        {
            parent[ulp_u] = ulp_v;
        }
        else
        {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUltParent(u);
        int ulp_v = findUltParent(v);

        if (ulp_u == ulp_v)
            return;
        int size_ulp_u = size[ulp_u];
        int size_ulp_v = size[ulp_v];
        if (size_ulp_u < size_ulp_v)
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size_ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size_ulp_v;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        DisjointSet ds(n);
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            if(ds.findUltParent(u)==ds.findUltParent(v)){
                return it;
            } else{
                ds.unionByRank(u,v);
            }
        }
        return ans;
    }
};