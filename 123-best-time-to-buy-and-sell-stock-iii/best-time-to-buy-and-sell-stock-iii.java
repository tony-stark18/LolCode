class Solution {
    public int f(int ind, int holding, int cap, int prices[],int [][][] dp) {
        if (ind == prices.length || cap == 0)
            return 0;
        if(dp[ind][holding][cap]!=-1) return dp[ind][holding][cap];
        if (holding == 0) {
            int buy = -prices[ind] + f(ind + 1, 1, cap, prices,dp);
            int skip = 0 + f(ind + 1, 0, cap, prices,dp);
            return dp[ind][holding][cap] = Math.max(buy, skip);
        } else {
            int sell = prices[ind] + f(ind + 1, 0, cap - 1, prices,dp);
            int nSell = f(ind + 1, 1, cap, prices,dp);
            return dp[ind][holding][cap] = Math.max(sell, nSell);
        }
    }

    public int maxProfit(int[] prices) {
        int [][][] dp= new int[prices.length][2][3];
        for(int i=0;i<prices.length;i++){
            for(int j=0;j<2;j++){
                Arrays.fill(dp[i][j],-1);
            }
        }
        return f(0,0,2,prices,dp);
    }
}