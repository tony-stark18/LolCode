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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> map;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(map.find(mail)==map.end()){
                    map[mail]=i;
                }
                else{
                    ds.unionBySize(i,map[mail]);
                }
            }
        }
        vector<vector<string>> mails(n);
        for(auto it:map){
            string mail = it.first;
            int node = ds.findUltParent(it.second);
            mails[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mails[i].size()==0) continue;
            sort(mails[i].begin(),mails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mails[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;

    }
};