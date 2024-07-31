class Solution {
public:
    int helper(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int count = 0;
        int sum = 0;
        int left = 0;
        int right = 0;
        while(right<nums.size()){
            sum+=nums[right];
            while(left<=right && sum>goal){
                sum = sum-nums[left];
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal)-helper(nums,goal-1);
    }
};