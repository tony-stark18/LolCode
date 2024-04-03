class Solution {

    public int solve(int i, int j, int n, List<List<Integer>> triangle, int dp[][]){
        if(dp[i][j] != -1)return dp[i][j];
        if(i==n)return dp[i][j]=0;

        return dp[i][j]=triangle.get(i).get(j) + Math.min(solve(i+1, j, n, triangle, dp), solve(i+1, j+1, n, triangle, dp));     
    }

    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int m = triangle.get(n-1).size();
        int dp[][] = new int[n+1][m+1];
        
        for(int arr[] : dp){
            Arrays.fill(arr, -1);
        }

        return solve(0, 0, n, triangle, dp);
    }
}