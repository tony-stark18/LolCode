class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int ans = Integer.MAX_VALUE;
        int left  = 0;
        int sum = 0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];

            while(sum>=target){
                ans=Math.min(ans,i-left+1);
                sum-=nums[left];
                left++;
            }
        }
        if(ans==Integer.MAX_VALUE) return 0;
        return ans;
    }
}