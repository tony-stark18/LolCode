class Solution {
    public int soln(int ind, int holding, int prices[], int dp[][]) {
        if (ind >= prices.length)
            return 0;
        if (dp[ind][holding] != -1)
            return dp[ind][holding];
        if (holding == 0) {
            int buy = -prices[ind] + soln(ind + 1, 1, prices, dp);
            int skip = 0 + soln(ind + 1, 0, prices, dp);
            return dp[ind][holding] = Math.max(buy, skip);
        } else {
            int sell = prices[ind] + soln(ind + 2, 0, prices, dp);
            int nSell = 0 + soln(ind + 1, 1, prices, dp);
            return dp[ind][holding] = Math.max(sell, nSell);
        }
    }

    public int maxProfit(int[] prices) {
        int n = prices.length;
        int dp[][] = new int[n + 2][2];
        
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int holding = 0; holding <= 1; holding++) {
                if (holding == 0) {
                    int buy = -prices[ind] + dp[ind + 1][1];
                    int skip = 0 + dp[ind + 1][0];
                    dp[ind][holding] = Math.max(buy, skip);
                } else {
                    int sell = prices[ind] + dp[ind + 2][0];
                    int nSell = 0 + dp[ind + 1][1];
                    dp[ind][holding] = Math.max(sell, nSell);
                }
            }
        }
        return dp[0][0];
    }
}