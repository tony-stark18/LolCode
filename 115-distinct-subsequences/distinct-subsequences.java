class Solution {
    public int soln(char arr1[], char arr2[], int i, int j, int dp[][]) {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (arr1[i] == arr2[j])
            return dp[i][j] = soln(arr1, arr2, i - 1, j - 1, dp) + soln(arr1, arr2, i - 1, j, dp);
        return dp[i][j] = soln(arr1, arr2, i - 1, j, dp);
    }

    public int numDistinct(String s, String t) {
        char arr1[] = s.toCharArray();
        char arr2[] = t.toCharArray();
        // int dp[][] = new int[arr1.length][arr2.length];
        // for (int i = 0; i < arr1.length; i++) {
        // Arrays.fill(dp[i], -1);
        // }
        // return soln(arr1, arr2, arr1.length - 1, arr2.length - 1, dp);
        int dp[][] = new int[arr1.length + 1][arr2.length + 1];
        for (int i = 0; i < arr1.length; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= arr1.length; i++) {
            for (int j = 1; j <= arr2.length; j++) {
                if (arr1[i-1] == arr2[j-1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[arr1.length][arr2.length];
    }
}