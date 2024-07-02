class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        boolean dp[][] = new boolean[nums.length][target + 1];
        for (int i = 0; i < nums.length; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <nums.length; i++) {
            for (int j = 1; j <= target; j++) {
                int currEl = nums[i];
                if (currEl <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - currEl];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[nums.length-1][target];

    }
}