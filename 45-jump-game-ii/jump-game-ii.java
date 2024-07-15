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
        if (nums.length == 1) return 0; // Edge case: single element
        int[] memo = new int[nums.length];
        Arrays.fill(memo, -1);
        return f(0, nums, memo);
    }
}
