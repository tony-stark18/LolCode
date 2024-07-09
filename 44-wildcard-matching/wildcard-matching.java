class Solution {
    public boolean soln(int i, int j, char[] s, char[] t, int dp[][]) {
        if (i < 0 && j < 0)
            return true;
        if (j < 0)
            return false;
        if (i < 0) {
            for (int k = 0; k <= j; k++) {
                if (t[k] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return (dp[i][j] == 1) ? true : false;
        if (s[i] == t[j] || t[j] == '?') {
            boolean res = soln(i - 1, j - 1, s, t, dp);
            dp[i][j] = (res) ? 1 : 0;
            return res;
        } else if (t[j] == '*') {
            boolean nTake = soln(i, j - 1, s, t, dp);
            boolean take = soln(i - 1, j, s, t, dp);
            dp[i][j] = (nTake || take) ? 1 : 0;
            return nTake || take;
        } else {
            dp[i][j] = 0;
            return false;
        }
    }

    public boolean isMatch(String s, String p) {
        char arr1[] = s.toCharArray();
        char arr2[] = p.toCharArray();
        int dp[][] = new int[arr1.length][arr2.length];
        for (int i = 0; i < arr1.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        return soln(arr1.length - 1, arr2.length - 1, arr1, arr2, dp);
    }
}