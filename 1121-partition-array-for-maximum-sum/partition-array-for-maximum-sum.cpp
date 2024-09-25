class Solution {
public:
    int f(int i, int k, int n, vector<int>& arr,vector<int> &dp) {
        if (i == n)
            return 0;
        if(dp[i]!=-1) return dp[i];
        int maxV = INT_MIN;
        int maxPoints = INT_MIN;
        for (int j = i; j < i + k; j++) {
            if (j < n) {
                maxV = max(maxV, arr[j]);
                int points = maxV * (j - i + 1) + f(j + 1, k, n, arr,dp);
                maxPoints = max(maxPoints,points);
            }
        }
        return dp[i] = maxPoints;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return f(0, k, n , arr,dp);
    }
};