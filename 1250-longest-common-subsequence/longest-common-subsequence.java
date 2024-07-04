class Solution {
    public int soln(char[] arr1,char[] arr2,int ind1,int ind2,int dp[][]){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(arr1[ind1]==arr2[ind2]) return dp[ind1][ind2] = 1+soln(arr1,arr2,ind1-1,ind2-1,dp);
        return dp[ind1][ind2] = Math.max(soln(arr1,arr2,ind1-1,ind2,dp),soln(arr1,arr2,ind1,ind2-1,dp));
    }
    public int longestCommonSubsequence(String text1, String text2) {
        char[] arr1 = text1.toCharArray();
        char[] arr2 = text2.toCharArray();
        int dp[][] = new int[arr1.length][arr2.length];
        for(int i=0;i<arr1.length;i++){
            Arrays.fill(dp[i],-1);
        }
        return soln(arr1,arr2,arr1.length-1,arr2.length-1,dp);
    }
}