class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int minLen = Integer.MAX_VALUE;
        for(right=0;right<nums.length;right++){
            if(nums[right]==target) return 1;
            sum+=nums[right];
            while(sum>=target){
                minLen = Math.min(right-left+1,minLen);
                sum-=nums[left];
                left++;
            }
        }
        if(minLen==Integer.MAX_VALUE) return 0;
        return minLen;
    }
}