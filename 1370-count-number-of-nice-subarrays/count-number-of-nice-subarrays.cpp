class Solution {
public:
    int helper(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int count = 0;
        int sum = 0;
        int left = 0;
        int right = 0;
        while(right<nums.size()){
            sum+=(nums[right])%2;
            while(left<=right && sum>goal){
                sum = sum-(nums[left]%2);
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};