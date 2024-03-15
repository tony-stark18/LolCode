class Solution {
    public int soln(int n,int dp[]){
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=0) return dp[n];
        dp[n] = soln(n-1,dp)+soln(n-2,dp);
        return dp[n];
    }
    public int climbStairs(int n) {
        int dp[] = new int[n+1];
        return soln(n,dp);
    }
}