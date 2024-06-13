class Solution {
    public int findKthPositive(int[] arr, int k) {
        for(int i:arr){
            if(i>k) return k;
            else k++;
        }
        return k;
    }
}