class Solution {
    public void reverse(char arr[]){
        int i=0;
        int j=arr.length-1;
        while(i<=j){
            char t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }
    public int longestPalindromeSubseq(String s) {
        char[] s1 =s.toCharArray();
        char[] s2 =s.toCharArray();
        reverse(s2);
        int n = s1.length;
        int dp[][] = new int[n+1][n+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
}