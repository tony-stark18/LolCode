class Solution {
    public int countSubstrings(String s) {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        int cnt = 0;

        // All single characters are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            cnt++;
        }

        // Check palindromes of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                dp[i][i + 1] = true;
                cnt++;
            }
        }

        // Check palindromes of length 3 or more
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (dp[i + 1][j - 1] && s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }

        return cnt;
    }
}
