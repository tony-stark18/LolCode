class Solution {
    public int missingNumber(int[] nums) {
        int n=nums.length;
        int o_sum = n*(n+1)/2;
        int a_sum=0;
        for(int i=0;i<n;i++){
            a_sum+=nums[i];
        }
        return o_sum-a_sum;
    }
}