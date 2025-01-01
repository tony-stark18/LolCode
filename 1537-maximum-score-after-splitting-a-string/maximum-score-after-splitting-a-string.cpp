class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> ones(n,0);
        ones[n-1]=(s[n-1]=='1')?1:0;
        for(int i=s.length()-2;i>=0;i--){
            if(s[i]=='1') ones[i]=ones[i+1]+1;
            else ones[i] = ones[i+1];
        }
        int ans = 0;
        int zeros = (s[0]=='0')?1:0;
        for(int i=1;i<s.length();i++){
            ans = max(ans,zeros+ones[i]);
            if(s[i]=='0') zeros++;
        }
        return ans;
    }
};