class Solution {
public:
    bool f(int i, int n, string& s, unordered_set<string>& set,
           vector<int>& dp) {
        if (i == n)
            return true;
        if (dp[i] != -1)
            return dp[i];
        bool ans = false;
        for (int j = i; j < n; j++) {
            string str = s.substr(i, j - i + 1);
            if (set.find(str) != set.end()) {
                bool res = f(j + 1, n, s, set, dp);
                ans = ans || res;
            }
        }
        return dp[i] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> set;
        for (const string& s : wordDict) {
            set.insert(s);
        }
        vector<int> dp(n + 1, 1);
        for (int i = n - 1; i >= 0; i--) {
            bool ans = false;
            for (int j = i; j < n; j++) {
                string str = s.substr(i, j - i + 1);
                if (set.find(str) != set.end()) {
                    bool res = dp[j + 1];
                    ans = ans || res;
                }
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};