class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int ntake = dp[i-1];
            int take = nums[i];
            if(i>1){
                take +=dp[i-2];
            }
            dp[i]=max(take,ntake);
        }
        return dp[n-1];
    }
};