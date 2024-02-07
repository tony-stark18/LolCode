class Solution {
    public int titleToNumber(String columnTitle) {
        double res = 0;
        int x =64;
        int n = columnTitle.length();
        for(int i=n-1;i>=0;i--){
            int d = (int)columnTitle.charAt(i);
            res = res + (d-x)*Math.pow(26,n-1-i);
        }
        return (int)res;
    }
}