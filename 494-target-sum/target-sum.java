class Solution {
    public int soln(int[] nums,int target,int ind,HashMap<String,Integer> dp){
        String key = ind + "," + target;
        if(dp.containsKey(key)) return dp.get(key);
        if(ind<0) return target==0?1:0;
        int plus = soln(nums,target-nums[ind],ind-1,dp);
        int minus = soln(nums,target+nums[ind],ind-1,dp);
        dp.put(key,plus+minus);
        return plus+minus;
    }
    public int findTargetSumWays(int[] nums, int target) {
        HashMap<String,Integer> dp = new HashMap<>();
        return soln(nums,target,nums.length-1,dp);
    }
}