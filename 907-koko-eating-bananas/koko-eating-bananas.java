class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1;
        int right = 1000000000;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(totalTime(piles, mid) <= h){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;

    }
    private long totalTime(int[] piles, int speed){
        long time = 0;
        for(int i = 0; i < piles.length; i++){
            time += piles[i] / speed;
            if(piles[i] % speed > 0){
                time++;
            } 
        }
        return time;
    }
}