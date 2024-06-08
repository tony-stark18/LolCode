class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> hs = new HashMap<>();
        hs.put(0, -1);
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            int rem = sum % k;
            if (hs.containsKey(rem)) {
                if (i - hs.get(rem) > 1)
                    return true;
            } else {
                hs.put(rem, i);
            }
        }
        return false;
    }
}