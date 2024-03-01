class Solution {
    public char findTheDifference(String s, String t) {
        char[] arr1 = s.toCharArray();
        char[] arr2 = t.toCharArray();
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        for(int i=0;i<s.length();i++){
            if(arr1[i]!=arr2[i]) return arr2[i];
        }
        return arr2[t.length()-1];
    }
}