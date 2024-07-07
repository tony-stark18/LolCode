class Solution {
    public int numWaterBottles(int n, int e) {
        int ans = n;
        while(n>=e){
            ans += n/e;
            n = (n/e)+n%e;
        }
        return ans;
    }
}