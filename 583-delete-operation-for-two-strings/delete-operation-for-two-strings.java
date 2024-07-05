class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        char[] arr1 = text1.toCharArray();
        char[] arr2 = text2.toCharArray();
        int dp[][] = new int[arr1.length + 1][arr2.length + 1];
        for (int ind1 = 1; ind1 <= arr1.length; ind1++) {
            for (int ind2 = 1; ind2 <= arr2.length; ind2++) {
                if (arr1[ind1 - 1] == arr2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else
                    dp[ind1][ind2] = Math.max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
        return dp[arr1.length][arr2.length];
    }
    public int minDistance(String word1, String word2) {
        int n = longestCommonSubsequence(word1,word2);
        return word1.length()-n+word2.length()-n;
    }
}