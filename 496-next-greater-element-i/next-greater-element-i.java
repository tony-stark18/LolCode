class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer, Integer> nextGreater = new HashMap<>();
        Stack<Integer> stack = new Stack<>();
        
        // Traverse nums2 to find the next greater element for each element
        for (int num : nums2) {
            while (!stack.isEmpty() && stack.peek() < num) {
                nextGreater.put(stack.pop(), num);
            }
            stack.push(num);
        }
        
        // Initialize the result array with -1
        int[] result = new int[nums1.length];
        Arrays.fill(result, -1);
        
        // Fill the result array by looking up the next greater element for each element in nums1
        for (int i = 0; i < nums1.length; i++) {
            if (nextGreater.containsKey(nums1[i])) {
                result[i] = nextGreater.get(nums1[i]);
            }
        }
        
        return result;
    }
}