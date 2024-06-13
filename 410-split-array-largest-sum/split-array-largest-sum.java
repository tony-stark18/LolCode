class Solution {
    public static int helper(int[] A,int pages){
        int stu = 1;
        int pg  = 0;
        for(int i:A){
            if(pg+i<=pages){
                pg = pg+i;
            }
            else{
                stu++;
                pg = i;
            }
        }
        return stu;
    }
    public int splitArray(int[] A, int M) {
        if(A.length<M) return -1;
        int high = 0;
        int low = 0;
        for(int i:A){
            high+=i;
            low = Math.max(i,low);
        }
        while(low<=high){
            int mid = (low+high)/2;
            int stu = helper(A,mid);
            if(stu<=M){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
}