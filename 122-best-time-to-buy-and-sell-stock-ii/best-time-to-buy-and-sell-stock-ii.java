class Solution {
    public int soln(int[] prices, int ind, int holding, int[][] dp) {
        if (ind == prices.length)
            return 0;
        if (dp[ind][holding] != -1)
            return dp[ind][holding];

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
        // int[][] dp = new int[n + 1][2];
        int[] prev = new int[2];
        int[] curr = new int[2];
        // for (int[] row : dp) Arrays.fill(row, -1);
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int holding = 0; holding <= 1; holding++) {
                if (holding == 0) {
                    int buy = -prices[ind] + prev[1];
                    int skip = prev[0];
                    curr[holding] = Math.max(buy, skip);
                } else {
                    int sell = prices[ind] + prev[0];
                    int hold = prev[1];
                    curr[holding] = Math.max(sell, hold);
                }
            }
            prev = curr.clone();
        }
        return prev[0];
    }
}