class Solution {
    public int pivotInteger(int n) {
        if(n==1) return 1;
        int oSum = n*(n+1)/2;
        int t = (int)Math.sqrt(oSum);
        if(t*t==oSum) return t;
        return -1;
    }
}