class Solution {
    public int tribonacci(int n) {
        if(n==0) return 0;
        if(n<3) return 1;
        int a = 0;
        int b = 1;
        int c = 1;
        for(int i=3;i<=n;i++){
            int t = c;
            c = a+b+c;
            a=b;
            b=t;
        }
        return c;
    }
}