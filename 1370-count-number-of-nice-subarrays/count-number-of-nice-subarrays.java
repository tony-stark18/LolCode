class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    private int atMost(int[] nums, int k) {
        int left = 0, right = 0;
        int count = 0, result = 0;

        while (right < nums.length) {
            if (nums[right] % 2 != 0) {
                k--;
            }
            while (k < 0) {
                if (nums[left] % 2 != 0) {
                    k++;
                }
                left++;
            }
            result += right - left + 1;
            right++;
        }

        return result;
    }
}
