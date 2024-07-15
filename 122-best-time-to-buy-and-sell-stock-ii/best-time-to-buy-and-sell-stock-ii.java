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
        // int[] prev = new int[2];
        int prev0 = 0;
        int prev1 = 0;
        int curr0 = 0;
        int curr1 = 0;
        int[] curr = new int[2];
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int holding = 0; holding <= 1; holding++) {
                if (holding == 0) {
                    int buy = -prices[ind] + prev1;
                    int skip = prev0;
                    curr0 = Math.max(buy, skip);
                } else {
                    int sell = prices[ind] + prev0;
                    int hold = prev1;
                    curr1 = Math.max(sell, hold);
                }
            }
            prev0 = curr0;
            prev1 = curr1;
        }
        return prev0;
    }
}