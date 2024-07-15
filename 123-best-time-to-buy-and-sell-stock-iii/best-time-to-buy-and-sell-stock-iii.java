class Solution {
    public int f(int ind, int hcap, int prices[], int[][] dp) {
        if (ind == prices.length || hcap == 4)
            return 0;
        if (dp[ind][hcap] != -1)
            return dp[ind][hcap];
        if (hcap % 2 == 0) {
            int buy = -prices[ind] + f(ind + 1, hcap + 1, prices, dp);
            int skip = 0 + f(ind + 1, hcap, prices, dp);
            return dp[ind][hcap] = Math.max(buy, skip);
        } else {
            int sell = prices[ind] + f(ind + 1, hcap + 1, prices, dp);
            int nSell = f(ind + 1, hcap, prices, dp);
            return dp[ind][hcap] = Math.max(sell, nSell);
        }
    }

    public int maxProfit(int[] prices) {
        int[] after = new int[5];
        int[] curr = new int[5];
        for (int ind = prices.length - 1; ind >= 0; ind--) {
            for (int hcap = 3; hcap >= 0; hcap--) {
                if (hcap % 2 == 0) {
                    int buy = -prices[ind] + after[hcap + 1];
                    int skip = after[hcap];
                    curr[hcap] = Math.max(buy, skip);
                } else {
                    int sell = prices[ind] + after[hcap + 1];
                    int nSell = after[hcap];
                    curr[hcap] = Math.max(sell, nSell);
                }
            }
            after = curr.clone();
        }
        return after[0];
    }
}