class Solution {
    public boolean search(int[] nums, int target) {
        int n = nums.length;
        int left = 0;
        int right = n-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[left] && nums[left]==nums[right]){
                left++;
                right--;
                continue;
            }
            else if(nums[mid]>=nums[left]){
                if(target>=nums[left] && target<=nums[mid]) right=mid-1;
                else left = mid+1;
            }
            else if(nums[mid]<=nums[right]){
                if(target<=nums[right] && target>=nums[mid]) left = mid+1;
                else right = mid-1;
            }
        } 
        return false;
    }
}