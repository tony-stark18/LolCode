class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> ans(2);
        for(int i=0;i<nums.size();i++){
            if(map.find(target-nums[i])!=map.end()){
                ans[0]=map[target-nums[i]];
                ans[1] = i;
            }
            map[nums[i]]=i;
        }
        return ans;
    }
};