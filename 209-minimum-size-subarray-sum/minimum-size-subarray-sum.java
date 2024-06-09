class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int ans = Integer.MAX_VALUE;
        int currSum = 0;
        int left = 0;

        for(int right = 0; right < nums.length; right++) {
            currSum += nums[right];

            while (currSum >= target) {
                ans = Math.min(ans, right - left + 1);
                currSum -= nums[left];
                left++;
            }
        }

        return ans == Integer.MAX_VALUE ? 0 : ans;
    }
}