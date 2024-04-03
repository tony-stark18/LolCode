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
                int tmin = Integer.MAX_VALUE;
                for(int k=0;k<n;k++){
                    if(k!=j){
                        tmin=Math.min(tmin,dp[i-1][k]);
                    }
                }
                dp[i][j] = matrix[i][j]+tmin;
                if(i==n-1) min=Math.min(dp[i][j],min);
            }
        }
        return min;
    }
}