class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        if (n == 1) return matrix[0][0];
        
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            dp[i] = matrix[0][i];
        }
        
        for (int i = 1; i < n; i++) {
            int[] temp = new int[n];
            for (int j = 0; j < n; j++) {
                int min = Integer.MAX_VALUE;
                for (int k = 0; k < n; k++) {
                    if (k != j) {
                        min = Math.min(min, dp[k]);
                    }
                }
                temp[j] = matrix[i][j] + min;
            }
            dp = temp;
        }
        
        int minSum = Integer.MAX_VALUE;
        for (int sum : dp) {
            minSum = Math.min(minSum, sum);
        }
        
        return minSum;
    }
}
