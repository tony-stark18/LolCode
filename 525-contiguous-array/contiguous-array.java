class Solution {
    public int findMaxLength(int[] nums) {
         int maxLength = 0;
        int balance = 0;
        int[] balanceIndices = new int[2 * nums.length + 1]; // To store last occurrence index for each balance value
        Arrays.fill(balanceIndices, -2); // Initialize with -2 (to handle indices starting from -1)
        balanceIndices[nums.length] = -1; // Initial balance is 0 at index -1
        
        for (int i = 0; i < nums.length; i++) {
            balance += nums[i] == 0 ? -1 : 1;
            
            if (balanceIndices[balance + nums.length] != -2) {
                maxLength = Math.max(maxLength, i - balanceIndices[balance + nums.length]);
            } else {
                balanceIndices[balance + nums.length] = i;
            }
        }
        
        return maxLength;
    }
}