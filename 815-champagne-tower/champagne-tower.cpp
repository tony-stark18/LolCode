class Solution {
public:
    double soln(int i, int j, int p, vector<vector<double>>& dp) {
        if (i == 0 && j == 0) {
            return dp[i][j] = p > 1 ? (p - 1) / 2.0 : 0.0;
        }
        if (i < 0 || j < 0 || j > i) {
            return 0.0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        double left = soln(i - 1, j - 1, p, dp);
        double right = soln(i - 1, j, p, dp);

        double total = left + right;
        return dp[i][j] = total > 1 ? (total - 1) / 2.0 : 0.0;
    }
    double champagneTower(int poured, int row, int glass) {
        // if (poured == 0)
        //     return 0.0;
        if (row == 0 && glass == 0)
            return poured > 1 ? 1.0 : poured;
        vector<vector<double>> dp(row + 1,
                                  vector<double>(glass + 1, (double)-1));
        double res = soln(row - 1, glass - 1, poured, dp) +
                     soln(row - 1, glass, poured, dp);
        if (res > 1)
            return 1.0;
        return res;
    }
};