class Solution {
    public int f(int ind, int prevInd, int[] nums,int dp[][]) {
        if (ind == nums.length)
            return 0;
        if(dp[ind][prevInd+1]!=-1) return dp[ind][prevInd+1];
        int nTake = f(ind + 1, prevInd, nums,dp);
        int take = Integer.MIN_VALUE;
        if (prevInd == -1 || nums[ind] > nums[prevInd]) {
            take = 1 + f(ind + 1, ind, nums,dp);
        }
        return dp[ind][prevInd+1] = Math.max(take, nTake);
    }

    public int lengthOfLIS(int[] nums) {
        int dp[][] = new int[nums.length][nums.length+1];
        for(int[] arr:dp){
            Arrays.fill(arr,-1);
        }
        return f(0, -1, nums,dp);
    }
}