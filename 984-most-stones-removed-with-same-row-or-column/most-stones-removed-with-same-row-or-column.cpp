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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int max_row = 0;
        int max_col = 0;
        for(auto it:stones){
            max_row = max(max_row,it[0]);
            max_col = max(max_col,it[1]);
        }
        DisjointSet ds(max_row+max_col+2);
        unordered_set<int> unique_indices;
        for(int i=0;i<n;i++){
            int row = stones[i][0];
            int col = stones[i][1]+max_row+1;
            ds.unionByRank(row,col);
            unique_indices.insert(row);
            unique_indices.insert(col);
        }
        int nc = 0;
        for (int idx : unique_indices) {
            if (ds.findUltParent(idx) == idx) {
                nc++;
            }
        }
        return n-nc;
    }
};