class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int t = nums[0]+1;
        int ans = 0;
        for(int i=1;i<nums.size();i++){
            if(t>nums[i]){
                ans+=t-nums[i];
                t++;
            }
            else{
                t=nums[i]+1;
            }
        }
        return ans;
    }
};