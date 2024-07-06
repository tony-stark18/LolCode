class Solution {
public:
    int passThePillow(int n, int time) {
        if(time<n) return time+1;
        n=n-1;
        if((time/n)%2==0) return 1+time%n;
        return n-time%n+1;

        // if((n/time)%2==0) return n%time+1;
        // return n%time
    }
};