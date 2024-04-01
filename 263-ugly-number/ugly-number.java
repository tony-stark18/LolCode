class Solution {
    public boolean isPrime(int n){
        if(n<2) return false;
        for(int i=2;i<=Math.sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
    public boolean isUgly(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        while(n>1){
            if(n%2==0) n=n/2;
            else if(n%3==0) n=n/3;
            else if(n%5==0) n=n/5;
            else return false;
        }
        return true;
    }
}