class Solution {
    public int soln(int[][] grid,int r,int c,int dp[][]){
        if(r==grid.length-1 && c==grid[0].length-1){
            return grid[r][c];
        }
        if(r==grid.length || c==grid[0].length) return Integer.MAX_VALUE;
        if(dp[r][c]!=-1) return dp[r][c];        
        int right = soln(grid,r,c+1,dp);
        int down = soln(grid,r+1,c,dp);
        
        return dp[r][c]=grid[r][c]+Math.min(right,down);
    }
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int dp[][] = new int[m][n]; 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        return soln(grid,0,0,dp);
    }
}