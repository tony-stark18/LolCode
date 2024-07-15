class Solution {
    public int f(int ind, int hcap, int prices[],int [][] dp) {
        if (ind == prices.length || hcap == 4)
            return 0;
        if(dp[ind][hcap]!=-1) return dp[ind][hcap];
        if (hcap%2 == 0) {
            int buy = -prices[ind] + f(ind + 1,hcap+1, prices,dp);
            int skip = 0 + f(ind + 1, hcap, prices,dp);
            return dp[ind][hcap] = Math.max(buy, skip);
        } else {
            int sell = prices[ind] + f(ind + 1, hcap + 1, prices,dp);
            int nSell = f(ind + 1, hcap, prices,dp);
            return dp[ind][hcap] = Math.max(sell, nSell);
        }
    }

    public int maxProfit(int[] prices) {
        int [][] dp= new int[prices.length][4];
        for(int i=0;i<prices.length;i++){
            Arrays.fill(dp[i],-1);
        }
        return f(0,0,prices,dp);
    }
}