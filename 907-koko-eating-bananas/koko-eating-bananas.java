class Solution {
    public long helper(int[] piles,int k){
        long res = 0;
        for(int i:piles){
            res += (int) Math.ceil((double) i / k);
        }
        return res;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int low = 1;
        int high = 0;
        for(int i:piles){
            high = Math.max(i,high);
        }
        int ans = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            long res = helper(piles,mid);
            System.out.println(res);
            if(res<=h){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
}