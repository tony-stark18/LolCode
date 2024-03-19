class Solution {
    public int soln(int[] nums,int ind,int dp[]){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick = nums[ind]+soln(nums,ind-2,dp);
        int npick = 0+soln(nums,ind-1,dp);
        return dp[ind] = Math.max(pick,npick);
    }
    public int rob(int[] nums) {
        int dp[] = new int[nums.length];
        Arrays.fill(dp,-1);
        return soln(nums,nums.length-1,dp);
    }
}