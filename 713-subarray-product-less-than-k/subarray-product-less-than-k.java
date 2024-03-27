class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.length;
        int prod = 1;
        int count =0;
        while(i<n){
            while(j<n && prod*nums[j]<k){
                prod = prod*nums[j];
                j++;
            }
            count += j - i;
            prod/=nums[i];
            i++;
            if(i>j){
                j=i;
                prod=1;
            }
        }
        return count;
    }
}