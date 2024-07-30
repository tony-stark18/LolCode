class Solution {
    public int longestOnes(int[] nums, int k) {
        int zeros = 0;
        int left = 0;
        int right = 0;
        int ans = Integer.MIN_VALUE;
        while(right<nums.length){
            if(nums[right]==0) zeros++;
            if(zeros>k){
                if(nums[left]==0)
                    zeros--;
                left++;
            }
            ans = Math.max(ans,right-left+1);
            right++;
        }
        return ans;
    }
}