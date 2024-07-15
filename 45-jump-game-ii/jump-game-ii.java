class Solution {
    public int f(int index, int nums[], int[] memo) {
        int n = nums.length;
        if (index >= n - 1) return 0; // If we've reached or passed the last index
        if (memo[index] != -1) return memo[index]; // Return the precomputed value

        int maxReach = Math.min(index + nums[index], n - 1); // Determine the farthest we can reach from the current index
        int minJumps = Integer.MAX_VALUE;

        for (int i = index + 1; i <= maxReach; i++) {
            int jumps = f(i, nums, memo);
            if (jumps != Integer.MAX_VALUE) {
                minJumps = Math.min(minJumps, jumps + 1); // Update the minimum jumps needed
            }
        }

        memo[index] = minJumps; // Store the computed result in memo
        return minJumps;
    }

    public int jump(int[] nums) {
        int n = nums.length;
        if (n == 1) return 0; // No jumps needed if there's only one element

        int[] dp = new int[n];
        Arrays.fill(dp, Integer.MAX_VALUE); // Initialize the DP array with infinity
        dp[0] = 0; // Start point requires 0 jumps

        // Fill the dp array with minimum jumps to reach each position
        for (int i = 0; i < n; i++) {
            int maxReach = Math.min(i + nums[i], n - 1); // Determine the farthest we can reach from the current index
            for (int j = i + 1; j <= maxReach; j++) {
                dp[j] = Math.min(dp[j], dp[i] + 1); // Update the minimum jumps needed to reach position j
            }
        }

        return dp[n - 1];
    }
}
