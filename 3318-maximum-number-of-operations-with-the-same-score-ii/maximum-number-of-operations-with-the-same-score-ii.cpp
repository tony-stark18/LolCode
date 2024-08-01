class Solution {
public:
    int soln(int i, int j, vector<int>& nums, int sum,
             vector<vector<int>>& dp) {
        if (i > j || i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int soln1 = 0;
        int soln2 = 0;
        int soln3 = 0;
        if (nums[i] + nums[i + 1] == sum) {
            soln1 = 1 + soln(i + 2, j, nums, sum, dp);
        }
        if (nums[i] + nums[j] == sum) {
            soln2 = 1 + soln(i + 1, j - 1, nums, sum, dp);
        }
        if (nums[j - 1] + nums[j] == sum) {
            soln3 = 1 + soln(i, j - 2, nums, sum, dp);
        }
        return dp[i][j] = max(soln1, max(soln2, soln3));
    }
    int maxOperations(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        vector<vector<int>> dp1(j + 1, vector<int>(j + 1, -1));
        int sum1 = nums[i] + nums[i + 1];
        int soln1 = soln(i + 2, j, nums, sum1, dp1);
        int sum2 = nums[i] + nums[j];
        vector<vector<int>> dp2(j + 1, vector<int>(j + 1, -1));
        int soln2 = soln(i + 1, j - 1, nums, sum2, dp2);
        int sum3 = nums[j - 1] + nums[j];
        vector<vector<int>> dp3(j + 1, vector<int>(j + 1, -1));
        int soln3 = soln(i, j - 2, nums, sum3, dp3);
        return max(soln1, max(soln2, soln3)) + 1;
    }
};