class Solution {
    public int longestPalindrome(String s) {
        int[] charCounts = new int[128]; // Assuming ASCII characters
        for (char c : s.toCharArray()) {
            charCounts[c]++;
        }
        
        int count = 0;
        boolean hasOdd = false;
        
        for (int charCount : charCounts) {
            if (charCount % 2 == 0) {
                count += charCount;
            } else {
                count += charCount - 1;
                hasOdd = true;
            }
        }
        
        return hasOdd ? count + 1 : count;
    }
}
