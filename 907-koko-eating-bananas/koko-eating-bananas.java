class Solution {
    public int getHours(int[] piles,int n){
        int total_hour=0;
        for(int i=0;i<piles.length;i++){
            total_hour+=Math.ceil((double)piles[i]/(double)n);
        }
        return total_hour;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int max=piles[0];
        for(int i:piles){
            max=Math.max(max,i);
        }
        int low=1;
        int high=max;
        while(low<=high){
            int mid = (low+high)/2;
            int hour = getHours(piles,mid);
            System.out.println(hour);
            if(hour<=h){
                high=mid-1;
            }
            else if(hour>h){
                low=mid+1;
            }
        }
        return low;

    }
}