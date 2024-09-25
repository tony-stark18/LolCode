class Solution {
public:
    bool h(const string& binaryString, int start,int end) {
        int n = 0;
        int base = 1;

        for (int i = end; i >= start; --i) {
            if (binaryString[i] == '1') {
                n += base;
            }
            base *= 2;
        }

        while (n % 5 == 0) {
            n /= 5;
        }

        return n == 1;
    }
    int f(int i,int n,string &s,vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int minAns = 1e9;
        if(s[i]=='0') return dp[i] = 1e9;
        for(int j=i;j<n;j++){
            if(s[j]!='0' && h(s,i,j)){
                int ans = 1 + f(j+1,n,s,dp);
                minAns = min(ans,minAns);
            }
        }
        return dp[i] = minAns;
    }
    int minimumBeautifulSubstrings(string s) {
        int n = s.length();
        vector<int> dp(n,-1);
        int ans = f(0,n,s,dp);
        return ans>=1e9?-1:ans;
    }
};