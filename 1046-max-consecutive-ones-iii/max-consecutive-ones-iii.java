class Solution {
    public int longestOnes(int[] nums, int k) {
        int ans = Integer.MIN_VALUE;
        int left = 0;
        int right = 0;
        int zeros = 0;
        while(right<nums.length){
            if(nums[right]==0) zeros++;
            if(zeros>k){
                while(left<=right && nums[left]!=0){
                    left++;
                }
                zeros--;
                left++;
            }
            ans = Math.max(ans,right-left+1);
            right++;
        }
        return ans;
    }
}