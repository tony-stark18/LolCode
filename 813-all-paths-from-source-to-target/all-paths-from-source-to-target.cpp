class Solution {
public:
    void soln(int node,vector<vector<int>> &ans,vector<int> &ds,vector<vector<int>>& graph,int n){
        if(node==n-1){
            ans.push_back(ds);
            return;
        }
        for(auto it:graph[node]){
            ds.push_back(it);
            soln(it,ans,ds,graph,n);
            ds.pop_back();
        }

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> ds;
        ds.push_back(0);
        soln(0,ans,ds,graph,graph.size());
        return ans;
    }
};