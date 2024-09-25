int IO = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    bool isPalindrome(string& s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
    int f(int i, int n, string& s, vector<int>& dp) {
        if (i == n)
            return 0;
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
    int minCut(string str) {
        int n = str.size();
        // Create a DP array to store the minimum number of partitions.
        vector<int> dp(n + 1, 0);
        dp[n] = 0; // Initialize the last element to 0.

        // Loop through the string in reverse order.
        for (int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;
            // Consider all possible substrings starting from the current index.
            for (int j = i; j < n; j++) {
                if (isPalindrome(str,i,j)) {
                    // If the substring is a palindrome, calculate the cost and
                    // minimize it.
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        // Subtract 1 as it counts partitions, not cuts.
        return dp[0] - 1;
    }
};