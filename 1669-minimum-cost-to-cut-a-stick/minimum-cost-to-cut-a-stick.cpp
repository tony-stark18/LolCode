class Solution {
public:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int min_cost = 1e9;
        for (int k = i; k <= j; k++) {
            int cost = cuts[j + 1] - cuts[i - 1];
            cost += f(i, k - 1, cuts, dp);
            cost += f(k + 1, j, cuts, dp);
            min_cost = min(min_cost, cost);
        }
        return dp[i][j] = min_cost;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(),
                               vector<int>(cuts.size(), 0));
        for (int i = cuts.size() - 2; i >= 1; i--) {
            for (int j = i; j <= cuts.size() - 2; j++) {
                int min_cost = 1e9;
                for (int k = i; k <= j; k++) {
                    int cost = cuts[j + 1] - cuts[i - 1];
                    cost += dp[i][k - 1];
                    cost += dp[k + 1][j];
                    min_cost = min(min_cost, cost);
                }
                dp[i][j] = min_cost;
            }
        }
        return dp[1][cuts.size() - 2];
    }
};