class Solution {
public:
    int soln(vector<int>& nums,int i,int j,vector<vector<int>> &dp){
        if(j==nums.size()){
            return 0;
        }
        if(dp[i+1][j]!=-1) return dp[i+1][j];
        int ntake = soln(nums,i,j+1,dp);
        int take = 0;
        if(i==-1 || nums[i]<nums[j]){
            take = 1+soln(nums,j,j+1,dp);
        }
        return dp[i+1][j] = max(ntake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        return soln(nums,-1,0,dp);
    }
};