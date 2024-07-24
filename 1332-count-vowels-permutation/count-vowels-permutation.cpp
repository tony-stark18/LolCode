class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1000000007;
        long long dp[n+1][5];
        for(int i = 0; i < 5; i++) dp[1][i] = 1;
        for(int i = 2; i <= n; i++){
            dp[i][0] = dp[i-1][1] % mod;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % mod;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4]) % mod;
            dp[i][3] = (dp[i-1][2] + dp[i-1][4]) % mod;
            dp[i][4] = dp[i-1][0] % mod;
        }
        int ans = 0;
        for(int j = 0; j < 5; j++){
            ans = (ans + dp[n][j]) % mod; // Ensure result is within modulo
        }
        return ans;
    }
};
