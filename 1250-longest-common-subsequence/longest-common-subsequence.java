class Solution {
    public int soln(char text1[],char text2[],int i,int j,int dp[][]){
        if(i==text1.length || j==text2.length) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]){
            return dp[i][j] = 1+soln(text1,text2,i+1,j+1,dp);
        }
        return dp[i][j]=Math.max(soln(text1,text2,i+1,j,dp),soln(text1,text2,i,j+1,dp));
    }
    public int longestCommonSubsequence(String text1, String text2) {
        int dp[][] = new int[text1.length()][text2.length()];
        for(int i=0;i<text1.length();i++){
            Arrays.fill(dp[i],-1);
        }
        return soln(text1.toCharArray(),text2.toCharArray(),0,0,dp);
    }
}