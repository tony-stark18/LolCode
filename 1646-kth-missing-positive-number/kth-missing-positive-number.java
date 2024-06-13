class Solution {
    public int findKthPositive(int[] arr, int k) {
        int n = arr.length;
        int c = 0;
        int t = 0;
        for(int i=1;i<arr[n-1];i++){
            if(i==arr[t]){
                t++;
            }
            else{
                c++;
            }
            if(c==k) return i;
        }
        return arr[n-1]+k-c;
    }
}