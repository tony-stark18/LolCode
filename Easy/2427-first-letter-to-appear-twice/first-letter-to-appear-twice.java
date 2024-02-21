class Solution {
    public char repeatedCharacter(String s) {
        int arr[] = new int[26];
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(arr[c-'a']==1) return c;
            arr[c-'a']++;
        }
        return 'a';
    }
}