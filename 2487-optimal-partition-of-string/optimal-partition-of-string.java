class Solution {
    public int partitionString(String s) {
        int count = 0;
        HashSet<Character> hs = new HashSet<>();
        char arr[] = s.toCharArray();
        for (int i = 0; i < arr.length; i++) {
            if (hs.contains(arr[i])) {
                count++;
                hs.clear();
                hs.add(arr[i]);
            }
            else{
                hs.add(arr[i]);
            }
        }
        return count+1;
    }
}