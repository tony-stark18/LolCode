class Solution {
    public int f(int ind, int prevInd, int[] nums, int dp[][]) {
        if (ind == nums.length)
            return 0;
        if (dp[ind][prevInd + 1] != -1)
            return dp[ind][prevInd + 1];
        int nTake = f(ind + 1, prevInd, nums, dp);
        int take = Integer.MIN_VALUE;
        if (prevInd == -1 || nums[ind] > nums[prevInd]) {
            take = 1 + f(ind + 1, ind, nums, dp);
        }
        return dp[ind][prevInd + 1] = Math.max(take, nTake);
    }

    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int dp[][] = new int[n + 1][n + 1];

        // for(int[] arr:dp){
        // Arrays.fill(arr,-1);
        // }
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prevInd = ind-1; prevInd >=-1 ; prevInd--) {
                int nTake = dp[ind + 1][prevInd+1];
                int take = Integer.MIN_VALUE;
                if (prevInd == -1 || nums[ind] > nums[prevInd]) {
                    take = 1 + dp[ind + 1][ind+1];
                }
                dp[ind][prevInd + 1] = Math.max(take, nTake);
            }
        }
        return dp[0][0];
    }
}