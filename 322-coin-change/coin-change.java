class Solution {
    public int soln(int ind, int[] coins, int amount, int dp[][]) {
        if (ind == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return (int) 1e9;
        }
        if (dp[ind][amount] != -1)
            return dp[ind][amount];
        int nTake = 0 + soln(ind - 1, coins, amount, dp);
        int take = Integer.MAX_VALUE;
        if (amount >= coins[ind])
            take = 1 + soln(ind, coins, amount - coins[ind], dp);
        return dp[ind][amount] = Math.min(take, nTake);
    }

    public int coinChange(int[] coins, int amount) {
        int[][] dp = new int[coins.length][amount + 1];
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = (int) 1e9;
        }
        for (int i = 1; i < coins.length; i++) {
            for (int j = 0; j <= amount; j++) {
                int nTake = dp[i - 1][j];
                int take = Integer.MAX_VALUE;
                if (coins[i]<=j)
                    take = 1 + dp[i][j - coins[i]];
                dp[i][j] = Math.min(take, nTake);
            }
        }
        if(dp[coins.length-1][amount]>=1e9) return -1;
        return dp[coins.length-1][amount];
    }
}