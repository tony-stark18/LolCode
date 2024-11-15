class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length;
        int lp = 0;
        int rp = n - 1;
        while (lp < n - 1 && arr[lp] <= arr[lp + 1]) {
            lp++;
        }
        if (lp == n - 1) return 0;
        while (rp > 0 && arr[rp] >= arr[rp - 1]) {
            rp--;
        }
        int result = Math.min(n - lp - 1, rp);
        int i=0;
        while(i<=lp && rp<n){
            if(arr[i]<=arr[rp]){
                result = Math.min(result, rp - i - 1);
                i++;
            }
            else{
                rp++;
            }
        }
        return result;
    }
}
