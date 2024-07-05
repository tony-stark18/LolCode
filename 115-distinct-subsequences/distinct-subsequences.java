class Solution {

    public int numDistinct(String s, String t) {
        char arr1[] = s.toCharArray();
        char arr2[] = t.toCharArray();
        
        int prev[] = new int[arr2.length + 1];
        
        prev[0]=1;

        for (int i = 1; i <= arr1.length; i++) {
            for (int j = arr2.length; j >=1; j--) {
                if (arr1[i-1] == arr2[j-1])
                    prev[j] = prev[j - 1] + prev[j];
            }
        }
        return prev[arr2.length];
    }
}