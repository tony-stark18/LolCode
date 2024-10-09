class Solution {
public:
    int soln(vector<string>& strs,int m,int n,int i,vector<vector<vector<int>>> &dp){
        if(i==strs.size()){
            return 0;
        }
        if(dp[m][n][i]!=-1) return dp[m][n][i];
        int non_pick = 0+soln(strs,m,n,i+1,dp);
        int pick = 0;
        int zs = 0;
        int os = 0;
        for(char c:strs[i]){
            if(c=='0') zs++;
            else os++;
        }
        if(zs<=m && os<=n){
            pick = 1+soln(strs,m-zs,n-os,i+1,dp);
        }
        return dp[m][n][i] = max(pick,non_pick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));
        return soln(strs,m,n,0,dp);
    }
};