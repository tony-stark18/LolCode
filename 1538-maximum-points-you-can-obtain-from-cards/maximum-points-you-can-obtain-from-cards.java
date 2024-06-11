class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int n = cardPoints.length;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += cardPoints[i];
        }
        if (k == n) {
            return sum;
        }
        int ws = n-k;
        int cwSum = 0;
        for(int i=0;i<n-k;i++){
            cwSum+=cardPoints[i];
        }
        int mwSum = cwSum;
        for(int i=n-k;i<n;i++){
            cwSum = cwSum-cardPoints[i-n+k]+cardPoints[i];
            mwSum = Math.min(cwSum,mwSum);
        }
        return sum-mwSum;
    }
}