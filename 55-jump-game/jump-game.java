class Solution {
    public boolean soln(int[] nums, boolean[] dp, int index) {
        if (index >= nums.length - 1) {
            return true; // If we reach or go beyond the last index, return true
        }
        
        if (dp[index]) {
            return false; // If dp[index] is true, it means we have already visited this index and found it impossible to jump further
        }
        
        for (int i = 1; i <= nums[index]; i++) {
            if (soln(nums, dp, index + i)) {
                return true; // If jumping from current index to the next possible index returns true, return true
            }
        }
        
        dp[index] = true; // If none of the jumps from current index return true, mark this index as impossible to jump further
        return false;
    }

    public boolean canJump(int[] nums) {
        if (nums.length == 1 && nums[0] == 0) {
            return true; // Handling case where there's only one element in the array, and it's 0
        }
        
        boolean dp[] = new boolean[nums.length];
        return soln(nums, dp, 0);
    }
}
