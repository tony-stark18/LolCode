class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> map;
        for (auto it : arr) {
            map[it]++;
        }
        for(auto it : arr){
            if(map[it]==1){
                k--;
            }
            if(k==0) return it;
        }
        return "";
    }
};