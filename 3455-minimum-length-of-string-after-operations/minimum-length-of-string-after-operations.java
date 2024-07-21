class Solution {
    public int minimumLength(String s) {
        int count = 0;
        char arr[] = s.toCharArray();
        int freq[]= new int[26];
        for(char c:arr){
            freq[c-'a']++;
        }
        for(int i:freq){
            while(i>=3){
                count++;
                i=i-2;
            }
        }
        return arr.length-count*2;
    }
}