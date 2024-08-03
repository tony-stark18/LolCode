class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = INT_MIN;
        int zeros = 0;
        while(right<nums.size()){
            if(nums[right]==0) zeros++;
            if(zeros>k){
                while(left<=right && nums[left]!=0){
                    left++;
                }
                left++;
                zeros--;
            }
            ans = max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};