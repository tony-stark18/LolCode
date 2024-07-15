class Solution {
    public int soln(int ind, int holding, int prices[], int dp[][],int fee) {
        if (ind >= prices.length)
            return 0;
        if (dp[ind][holding] != -1)
            return dp[ind][holding];
        if (holding == 0) {
            int buy = -prices[ind] + soln(ind + 1, 1, prices, dp,fee);
            int skip = 0 + soln(ind + 1, 0, prices, dp,fee);
            return dp[ind][holding] = Math.max(buy, skip);
        } else {
            int sell = prices[ind]-fee + soln(ind + 1, 0, prices, dp,fee);
            int nSell = 0 + soln(ind + 1, 1, prices, dp,fee);
            return dp[ind][holding] = Math.max(sell, nSell);
        }
    }
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        int dp[][] = new int[n][2];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return soln(0,0,prices,dp,fee);
    }
}