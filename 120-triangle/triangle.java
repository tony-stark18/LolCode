class Solution {
    public int soln(List<List<Integer>> triangle, int i, int j, int[][] dp) {
        if (i == triangle.size()-1) return triangle.get(i).get(j);
        if (dp[i][j] != -1) return dp[i][j];
        int res1 = triangle.get(i).get(j) + soln(triangle, i + 1, j, dp);
        int res2 = triangle.get(i).get(j) + soln(triangle, i + 1, j+ 1, dp);
        return dp[i][j] = Math.min(res1, res2);
    }

    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[] dp = new int[n];
        int[] temp = new int[n];
        // for(int i=0;i<n;i++){
        //     Arrays.fill(dp[i],-1);
        // }
        // return soln(triangle, 0, 0, dp);
        for(int i=0;i<n;i++){
            dp[i]=triangle.get(n-1).get(i);
        }
        for(int i=n-2;i>=0;i--){
            for(int j=triangle.get(i).size()-1;j>=0;j--){
                temp[j]=Math.min(dp[j],dp[j+1])+triangle.get(i).get(j);
            }
            dp = temp.clone();
        }
        return dp[0];
    }
}
