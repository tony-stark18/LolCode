class Solution {
    public int soln(int[][] grid,int r,int c,int dp[][]){
        if(r==0 && c==0){
            return grid[r][c];
        }
        if(r<0 || c<0) return Integer.MAX_VALUE;
        if(dp[r][c]!=-1) return dp[r][c];        
        int left = soln(grid,r,c-1,dp);
        int up = soln(grid,r-1,c,dp);
        
        return dp[r][c]=grid[r][c]+Math.min(left,up);
    }
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int dp[][] = new int[m][n]; 
        for(int i=0;i<m;i++){
            Arrays.fill(dp[i],-1);
        }
        return soln(grid,m-1,n-1,dp);
    }
}