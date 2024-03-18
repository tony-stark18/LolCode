class Solution {
    public int f(int[] cost,int ind,int[] dp){
        if(ind==0 || ind==1) return cost[ind];
        if(dp[ind]!=-1) return dp[ind];
        int fs = f(cost,ind-1,dp);
        int ss = Integer.MAX_VALUE;
        if(ind>1)
            ss = f(cost,ind-2,dp);
        dp[ind] = Math.min(fs,ss)+cost[ind];
        return Math.min(fs,ss)+cost[ind];
    }
    public int minCostClimbingStairs(int[] cost) {
        int dp[] = new int[cost.length];
        for(int i=0;i<cost.length;i++) dp[i]=-1;
        return Math.min(f(cost,cost.length-1,dp),f(cost,cost.length-2,dp));
    }
}