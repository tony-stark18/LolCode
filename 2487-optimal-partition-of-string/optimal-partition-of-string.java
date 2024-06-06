class Solution {
    public int partitionString(String s) {
        int count = 0;
        boolean[] seen = new boolean[26]; // to track characters seen in the current partition
        char[] arr = s.toCharArray();
        
        for (char c : arr) {
            if (seen[c - 'a']) { // if the character is already seen in the current partition
                count++; // start a new partition
                seen = new boolean[26]; // reset the seen array
            }
            seen[c - 'a'] = true; // mark the character as seen
        }
        
        return count + 1; // add one for the last partition
    }
}
