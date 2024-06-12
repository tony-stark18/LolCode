class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==nums[mid-1]){
                if(mid%2!=0){
                    low = mid;
                }
                else{
                    high = mid;
                }
            }
            else if(nums[mid]==nums[mid+1]){
                if(mid%2==0){
                    low = mid;
                }
                else{
                    high = mid;
                }
            }
            else{
                return nums[mid];
            }
        }
        return -1;
    }
}