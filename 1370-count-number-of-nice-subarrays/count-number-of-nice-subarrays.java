import java.util.HashMap;

class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        HashMap<Integer, Integer> countMap = new HashMap<>();
        countMap.put(0, 1); // base case: one way to have 0 odd numbers with an empty subarray
        int oddCount = 0;
        int result = 0;

        for (int num : nums) {
            if (num % 2 != 0) {
                oddCount++;
            }
            if (countMap.containsKey(oddCount - k)) {
                result += countMap.get(oddCount - k);
            }
            countMap.put(oddCount, countMap.getOrDefault(oddCount, 0) + 1);
        }

        return result;
    }
}
