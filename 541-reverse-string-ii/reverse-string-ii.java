public class Solution {
    public String reverseStr(String s, int k) {
        int n = s.length();
        if (n < 2) {
            return s;
        }
        
        char[] charArray = s.toCharArray();
        
        for (int i = 0; i < n; i = i + 2 * k) {
            int l = i + k;
            int j = i;
            int x = Math.min(l - 1, n - 1);
            
            while (j <= x) {
                char temp = charArray[j];
                charArray[j] = charArray[x];
                charArray[x] = temp;
                j++;
                x--;
            }
        }
        
        return new String(charArray);
    }
}
