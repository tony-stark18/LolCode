int IO = []{
    ios::sync_with_stdio(false); cin.tie(nullptr); return 0;
}();
class Solution {
public:
    bool isPalindrome(string &s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
    int f(int i,int n, string &s, vector<int>& dp) {
        if (i == n) return 0;
        if (dp[i] != -1)
            return dp[i];
        int min_cuts = 1e9;
        for (int k = i; k < n; k++) {
            if (isPalindrome(s, i, k)) {
                int cuts = 1 + f(k + 1, n, s, dp);
                min_cuts = min(cuts, min_cuts);
            }
        }
        return dp[i] = min_cuts;
    }
    int minCut(string s) {
        int n = s.length();
        // if (isPalindrome(s, 0, n - 1))
        //     return 0;
        vector<int> dp(n,-1);
        // for (int i = n - 1; i >= 0; i--) {
        //     for (int j = i; j <= n - 1; j++) {
        //         int min_cuts = 1e9;
        //         for (int k = i; k <= j; k++) {
        //             if (isPalindrome(s, i, k)) {
        //                 int cuts = 1 + dp[k + 1][j];
        //                 min_cuts = min(cuts, min_cuts);
        //             }
        //         }
        //         dp[i][j] = min_cuts;
        //     }
        // }
        return f(0,n,s,dp)-1;
    }
};