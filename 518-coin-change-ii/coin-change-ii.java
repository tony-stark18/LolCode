class Solution {
    public int soln(int amount,int coins[],int ind,int dp[][]){
        if(amount==0) return 1;
        if(ind<0) return 0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int nTake = soln(amount,coins,ind-1,dp);
        int take = 0;
        if(coins[ind]<=amount){
            take = soln(amount-coins[ind],coins,ind,dp);
        }
        return dp[ind][amount] = take + nTake;
    }
    public int change(int amount, int[] coins) {
        // int dp[][] = new int[coins.length][amount+1];
        // for(int i=0;i<coins.length;i++){
        //     Arrays.fill(dp[i],-1);
        // }
        // return soln(amount,coins,coins.length-1,dp);
        int dp[][] = new int[coins.length][amount+1];
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
        }
        for(int ind=1;ind<coins.length;ind++){
            for(int tar=0;tar<=amount;tar++){
                int take = 0;
                int nTake = dp[ind-1][tar];
                if(coins[ind]<=tar) take = dp[ind][tar-coins[ind]];
                dp[ind][tar] = take+nTake;
            }
        }
        return dp[coins.length-1][amount];
    }
}