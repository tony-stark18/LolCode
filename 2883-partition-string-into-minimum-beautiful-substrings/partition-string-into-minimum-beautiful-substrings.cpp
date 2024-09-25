class Solution {
public:
    bool h(const string& binaryString, int start,int end) {
        int n = 0;
        int base = 1;

        for (int i = end; i >= start; --i) {
            if (binaryString[i] == '1') {
                n += base;
            }
            base *= 2; // Move to the next power of 2
        }

        while (n % 5 == 0) {
            n /= 5;
        }

        return n == 1;
    }
    int f(int i,int n,string &s){
        if(i==n) return 0;
        int minAns = 1e9;
        if(s[i]=='0') return 1e9;
        for(int j=i;j<n;j++){
            if(s[j]!='0' && h(s,i,j)){
                int ans = 1 + f(j+1,n,s);
                minAns = min(ans,minAns);
            }
        }
        return minAns;
    }
    int minimumBeautifulSubstrings(string s) {
        int ans = f(0,s.length(),s);
        return ans>=1e9?-1:ans;
    }
};