class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,int> map;
        for(int i=0;i<heights.size();i++){
            map[heights[i]]=i;
        }
        sort(heights.begin(),heights.end());

        vector<string> ans;
        for(int i=heights.size()-1;i>=0;i--){
            ans.push_back(names[map[heights[i]]]);
        }
        // for(int i:heights){
        //     ans.push_back(names[map[i]]);
        // }
        return ans;
    }
};