class Solution {
    public int appendCharacters(String s, String t) {
        int i=0;
        int j=0;
        int count = 0;
        char arr1[] = s.toCharArray();
        char arr2[] = t.toCharArray();
        while(i<arr1.length && j<arr2.length){
            if(arr1[i]==arr2[j]){
                count++;
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return arr2.length-count;
    }
}