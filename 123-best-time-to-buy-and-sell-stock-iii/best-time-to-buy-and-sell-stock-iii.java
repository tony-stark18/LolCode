class Solution {
    public int f(int ind, int holding, int cap, int prices[], int[][][] dp) {
        if (ind == prices.length || cap == 0)
            return 0;
        if (dp[ind][holding][cap] != -1)
            return dp[ind][holding][cap];
        if (holding == 0) {
            int buy = -prices[ind] + f(ind + 1, 1, cap, prices, dp);
            int skip = 0 + f(ind + 1, 0, cap, prices, dp);
            return dp[ind][holding][cap] = Math.max(buy, skip);
        } else {
            int sell = prices[ind] + f(ind + 1, 0, cap - 1, prices, dp);
            int nSell = f(ind + 1, 1, cap, prices, dp);
            return dp[ind][holding][cap] = Math.max(sell, nSell);
        }
    }

    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] after = new int[2][3];
        int[][] curr = new int[2][3];

        for (int ind = prices.length - 1; ind >= 0; ind--) {
            for (int holding = 0; holding <= 1; holding++) {
                for (int cap = 2; cap > 0; cap--) {
                    if (holding == 0) {
                        int buy = -prices[ind] + after[1][cap];
                        int skip = 0 + after[0][cap];
                        curr[holding][cap] = Math.max(buy, skip);
                    } else {
                        int sell = prices[ind] + after[0][cap - 1];
                        int nSell = after[1][cap];
                        curr[holding][cap] = Math.max(sell, nSell);
                    }
                }
            }
            after = curr.clone();
        }
        return after[0][2];
    }
}