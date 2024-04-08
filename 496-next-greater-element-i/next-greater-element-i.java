class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] nextGreater = new int[10001];
        Arrays.fill(nextGreater, -1);
        Stack<Integer> stack = new Stack<>();
        
        // Traverse nums2 to find the next greater element for each element
        for (int num : nums2) {
            while (!stack.isEmpty() && stack.peek() < num) {
                nextGreater[stack.pop()] = num;
            }
            stack.push(num);
        }
        
        // Initialize the result array with -1
        int[] result = new int[nums1.length];
        
        // Fill the result array by looking up the next greater element for each element in nums1
        for (int i = 0; i < nums1.length; i++) {
            result[i] = nextGreater[nums1[i]];
        }
        
        return result;
    }
}