import java.util.Arrays;

class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int num : nums) sum += num;

        // If the total sum is odd, it's not possible to partition into two equal subsets
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        boolean[] dp = new boolean[target + 1];
        dp[0] = true; 

        for (int num : nums) {
            boolean[] curr = Arrays.copyOf(dp, target + 1); 
            for (int j = num; j <= target; j++) {
                curr[j] = dp[j] || dp[j - num];
            }
            dp = curr;
        }

        return dp[target];
    }
}
