class Solution {
    public int soln(int ind,int[] coins,int amount,int dp[][]){
        if(ind==0){
            if(amount%coins[0]==0) return amount/coins[0];
            return (int)1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int take = 0+soln(ind-1,coins,amount,dp);
        int nTake = Integer.MAX_VALUE;
        if(amount>=coins[ind]) nTake = 1+soln(ind,coins,amount-coins[ind],dp);
        return dp[ind][amount]=Math.min(take,nTake);
    }
    public int coinChange(int[] coins, int amount) {
        int[][] dp = new int[coins.length][amount+1];
        for(int i=0;i<coins.length;i++){
            Arrays.fill(dp[i],-1);
        }
        int ans = soln(coins.length-1,coins,amount,dp);
        if(ans>=1e9) return -1;
        return ans;
    }
}