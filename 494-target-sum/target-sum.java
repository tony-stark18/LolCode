class Solution {
    public int soln(int[] nums,int target,int ind){
        if(ind<0) return target==0?1:0;
        int plus = soln(nums,target-nums[ind],ind-1);
        int minus = soln(nums,target+nums[ind],ind-1);
        return plus+minus;
    }
    public int findTargetSumWays(int[] nums, int target) {
        return soln(nums,target,nums.length-1);
    }
}