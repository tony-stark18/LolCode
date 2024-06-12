class Solution {
    public int helper(int[] arr,int k,int day){
        int count = 0;
        int bcount = 0;
        for(int i:arr){
            if(i<=day){
                count++;
            }
            else{
                bcount+=(count/k);
                count=0;
            }
        }
        bcount+=count/k;
        return bcount;
    }
    public int minDays(int[] bloomDay, int m, int k) {
        int n=bloomDay.length;
        if((long)m*k>(long)n) return -1;
        int minDay = bloomDay[0];
        int maxDay = bloomDay[0];
        for(int i:bloomDay){
            minDay=Math.min(minDay,i);
            maxDay=Math.max(maxDay,i);
        }
        while(minDay<=maxDay){
            int midDay = (minDay+maxDay)/2;
            int bcount = helper(bloomDay,k,midDay);
            if(bcount>=m) maxDay=midDay-1;
            else minDay = midDay+1;
        }
        return minDay;
    }
}