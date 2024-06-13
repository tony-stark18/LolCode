class Solution {
    public int findKthPositive(int[] nums, int k) {
        int low = 0;
        int high = nums.length-1;
        while(low<=high){
            int mid = (low+high)/2;
            int miss = nums[mid]-mid-1;
            if(miss>=k) high = mid-1;
            else low = mid+1;
        }
        return high+k+1;
    }
}