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
        int dp[] = new int[n];
        Arrays.fill(dp,1);
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    dp[i]=Math.max(dp[i],1+dp[j]);
                }
            }
        }   
        int ans = 0; 
        for(int i=0;i<n;i++){
            ans = Math.max(ans,dp[i]);
        }
        return ans;
    }
}