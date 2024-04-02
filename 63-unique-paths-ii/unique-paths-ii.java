class Solution {
    public int soln(int[][] obstacleGrid,int i,int j,int dp[][]){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = 0;
        int left  = 0;
        if(i>0 && obstacleGrid[i-1][j]!=1){
            up=soln(obstacleGrid,i-1,j,dp);
        }
        if(j>0 && obstacleGrid[i][j-1]!=1){
            left = soln(obstacleGrid,i,j-1,dp);
        }
        return dp[i][j]=up+left;
    }
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        int dp[][] = new int[m][n];
        for(int i=0;i<m;i++){
            Arrays.fill(dp[i],-1);
        }
        return soln(obstacleGrid,m-1,n-1,dp);
    }
}