class Solution {
    public int maxProfit(int k, int[] prices) {
        int[] after = new int[2*k+1];
        int[] curr = new int[2*k+1];
        for (int ind = prices.length - 1; ind >= 0; ind--) {
            for (int hcap = 2*k-1; hcap >= 0; hcap--) {
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