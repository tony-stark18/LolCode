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
        int n = cost.length;
        // int[] dp = new int[n];
        int a = cost[0];
        int b = cost[1];
        for (int i = 2; i < n; i++) {
            int t = b;
            b = cost[i] + Math.min(a, b);
            a=t;
        }
        return Math.min(a, b);
    }

}