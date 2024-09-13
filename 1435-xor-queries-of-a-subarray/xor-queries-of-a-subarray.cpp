class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xorR;
        int xorV = 0;
        for(auto& it:arr){
            xorV^=it;
            xorR.push_back(xorV);
        }
        vector<int> ans;
        for(auto it:queries){
            if(it[0]==0){
                ans.push_back(xorR[it[1]]);
            }
            else{
                ans.push_back(xorR[it[1]]^xorR[it[0]-1]);
            }
        }
        return ans;
    }
};