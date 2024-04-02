class Solution {
    public int soln(int i,int j,int dp[][]){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = soln(i-1,j,dp);
        int left = soln(i,j-1,dp);
        return dp[i][j] = up + left;
    }
    public int uniquePaths(int m, int n) {
        int dp[][] = new int[m][n];
        for(int i=0;i<m;i++){
            Arrays.fill(dp[i],-1);
        }
        return soln(m-1,n-1,dp);
    }
}