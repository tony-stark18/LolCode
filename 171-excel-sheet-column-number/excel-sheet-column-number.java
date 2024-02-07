class Solution {
    public int titleToNumber(String columnTitle) {
        int res = 0;
        int n = columnTitle.length();
        for (int i = n - 1; i >= 0; i--) {
            char c = columnTitle.charAt(i);
            int d = c - 'A' + 1;
            res = res + d * (int) Math.pow(26, n - 1 - i);
        }
        return res;
    }
}
