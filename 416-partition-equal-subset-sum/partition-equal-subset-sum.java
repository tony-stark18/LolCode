class Solution {
    // public boolean soln(int[] nums,int target,int ind,int dp[][]){
    // if(target==0) return true;
    // if(ind==0) return nums[0]==target;
    // if(dp[ind][target]!=-1) return (dp[ind][target]==1)?true:false;
    // boolean nTake = soln(nums,target,ind-1,dp);
    // boolean take=false;
    // if(nums[ind]<=target) take = soln(nums,target-nums[ind],ind-1,dp);
    // dp[ind][target]= (nTake || take)?1:0;
    // return nTake || take;
    // }
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum % 2 != 0)
            return false;
        // int dp[][] = new int[nums.length][(sum/2)+1];
        // for(int i=0;i<nums.length;i++){
        // Arrays.fill(dp[i],-1);
        // }
        // return soln(nums,sum/2,nums.length-1,dp);
        int target = sum / 2;
        boolean dp[][] = new boolean[nums.length+1][target + 1];
        for (int i = 0; i < nums.length; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= nums.length; i++) {
            for (int j = 1; j <= target; j++) {
                int currEl = nums[i - 1];
                if (currEl <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - currEl];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[nums.length][target];

    }
}