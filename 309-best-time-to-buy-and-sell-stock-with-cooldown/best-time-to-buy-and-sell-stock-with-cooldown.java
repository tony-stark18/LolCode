class Solution {
    public int soln(int ind,int holding,int prices[],int dp[][]){
        if(ind>=prices.length) return 0;
        if(dp[ind][holding]!=-1) return dp[ind][holding];
        if(holding==0){
            int buy = -prices[ind]+soln(ind+1,1,prices,dp);
            int skip = 0+soln(ind+1,0,prices,dp);
            return dp[ind][holding]  = Math.max(buy,skip);
        }
        else{
            int sell = prices[ind]+soln(ind+2,0,prices,dp);
            int nSell = 0 + soln(ind+1,1,prices,dp);
            return dp[ind][holding] = Math.max(sell,nSell);
        }
    }
    public int maxProfit(int[] prices) {
        int dp[][] = new int[prices.length][2];
        for(int i=0;i<prices.length;i++){
            Arrays.fill(dp[i],-1);
        }
        return soln(0,0,prices,dp);
    }
}