class Solution {
public:
    int soln(int i, int j, vector<vector<int>>& cb, vector<vector<int>> &dp) {
        if (i == cb.size()) return 0;
        
        if (dp[i][j + 1] != -1) return dp[i][j + 1];
        
        int npk = soln(i + 1, j, cb, dp);
        
        int pk = 0;
        if (j == -1 || (cb[i][0] <= cb[j][0] && cb[i][1] <= cb[j][1] && cb[i][2] <= cb[j][2])) {
            pk = cb[i][2] + soln(i + 1, i, cb, dp);
        }
        
        return dp[i][j + 1] = max(pk, npk);
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        vector<vector<int>> cb;
        for (auto it : cuboids) {
            sort(it.begin(), it.end());
            cb.push_back(it);
        }
        
        sort(cb.begin(), cb.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] > b[0];
            if (a[1] != b[1]) return a[1] > b[1];
            return a[2] > b[2];
        });
        
        vector<vector<int>> dp(cb.size() + 1, vector<int>(cb.size() + 1, -1));
        
        return soln(0, -1, cb, dp);
    }
};
