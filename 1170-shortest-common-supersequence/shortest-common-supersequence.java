class Solution {
    public void longestCommonSubsequence(char[] arr1, char[] arr2, int dp[][]) {
        for (int ind1 = 1; ind1 <= arr1.length; ind1++) {
            for (int ind2 = 1; ind2 <= arr2.length; ind2++) {
                if (arr1[ind1 - 1] == arr2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else
                    dp[ind1][ind2] = Math.max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
    }

    public String shortestCommonSupersequence(String text1, String text2) {
        char[] arr1 = text1.toCharArray();
        char[] arr2 = text2.toCharArray();
        int dp[][] = new int[arr1.length + 1][arr2.length + 1];
        longestCommonSubsequence(arr1,arr2,dp);
        int i = arr1.length;
        int j = arr2.length;
        StringBuilder sb = new StringBuilder("");
        while(i>0 && j>0){
            if(arr1[i-1]==arr2[j-1]){
                sb.append(arr1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                sb.append(arr1[i-1]);
                i--;
            }
            else{
                sb.append(arr2[j-1]);
                j--;
            }
        }
        while(i>0){
            sb.append(arr1[i-1]);
            i--;
        }
        while(j>0){
            sb.append(arr2[j-1]);
            j--;
        }
        sb.reverse();
        return sb.toString();
    }
}