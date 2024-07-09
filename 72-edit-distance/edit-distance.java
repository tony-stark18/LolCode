class Solution {
    public int soln(int i, int j, char[] arr1, char arr2[], int dp[][]) {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (arr1[i] == arr2[j])
            return dp[i][j] = soln(i - 1, j - 1, arr1, arr2, dp);
        int insert = 1 + soln(i, j - 1, arr1, arr2, dp);
        int delete = 1 + soln(i - 1, j, arr1, arr2, dp);
        int replace = 1 + soln(i - 1, j - 1, arr1, arr2, dp);
        return dp[i][j] = Math.min(insert, Math.min(delete, replace));
    }

    public int minDistance(String word1, String word2) {
        char arr1[] = word1.toCharArray();
        char arr2[] = word2.toCharArray();
        int m = arr1.length;
        int n = arr2.length;
        int dp[][] = new int[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr1[i - 1] == arr2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    int insert = 1 + dp[i][j - 1];
                    int delete = 1 + dp[i - 1][j];
                    int replace = 1 + dp[i - 1][j - 1];
                    dp[i][j] = Math.min(insert, Math.min(delete, replace));
                }
            }
        }
        return dp[m][n];
    }
}