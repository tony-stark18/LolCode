class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int left = 0;
        int right = 0;
        int ans = INT_MIN;
        while(right<nums.size()){
            if(nums[right]==0) zeros++;
            if(zeros>k){
                if(nums[left]==0)
                    zeros--;
                left++;
            }
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;

    }
};