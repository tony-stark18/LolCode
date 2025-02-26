class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return n;
        int a = 1;
        int b = 2;
        for(int i=3;i<=n;i++){
            int t = a;
            a=b;
            b=a+t;
        }
        return b;
    }
};