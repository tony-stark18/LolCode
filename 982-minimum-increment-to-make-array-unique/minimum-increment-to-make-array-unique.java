class Solution {
    public int minIncrementForUnique(int[] nums) {
        Arrays.sort(nums);
        int target = nums[0];  // Initialize target to nums[0]
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            if (target > nums[i]) {
                ans += target - nums[i];
            } else {
                target = nums[i];
            }
            target++;  // Increment target for the next position
        }
        return ans;
    }
}
