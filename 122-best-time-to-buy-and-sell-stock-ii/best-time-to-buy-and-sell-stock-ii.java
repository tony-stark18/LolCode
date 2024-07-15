class Solution {
    public int soln(int[] prices, int ind, int holding, int[][] dp) {
        if (ind == prices.length) return 0;
        if (dp[ind][holding] != -1) return dp[ind][holding];

        if (holding == 0) {
            int buy = -prices[ind] + soln(prices, ind + 1, 1, dp);
            int skip = soln(prices, ind + 1, 0, dp);
            dp[ind][holding] = Math.max(buy, skip);
        } else {
            int sell = prices[ind] + soln(prices, ind + 1, 0, dp);
            int hold = soln(prices, ind + 1, 1, dp);
            dp[ind][holding] = Math.max(sell, hold);
        }

        return dp[ind][holding];
    }

    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] dp = new int[n][2];
        for (int[] row : dp) Arrays.fill(row, -1);
        return soln(prices, 0, 0, dp);
    }
}