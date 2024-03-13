class Solution {
    public int pivotInteger(int n) {
        if(n==1) return 1;
        int oSum = n*(n+1)/2;
        int runningSum = 0;
        for(int i=1;i<n;i++){
            runningSum+=i;
            if(oSum+i-runningSum==runningSum) return i;
        }
        return -1;
    }
}