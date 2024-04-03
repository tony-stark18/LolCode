class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        if(n==1) return matrix[0][0];
        int[][] dp = new int[n][n];
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        int min = Integer.MAX_VALUE;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int res1 = Integer.MAX_VALUE;
                int res2 = dp[i-1][j];
                int res3 = Integer.MAX_VALUE;
                if(j>0) res1=dp[i-1][j-1];
                if(j<n-1) res3=dp[i-1][j+1];
                dp[i][j] = matrix[i][j]+Math.min(Math.min(res1,res2),res3);
                if(i==n-1) min=Math.min(dp[i][j],min);
            }
        }
        return min;
    }
}