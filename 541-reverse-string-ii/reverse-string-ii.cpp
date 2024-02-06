class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        if(n<2) return s;
        for(int i=0;i<n;i=i+2*k){ 
            int l = i+k; 
            int j = i;
            int x = min(l-1,n-1);
            while(j<=x){
                char t = s[j];
                s[j]=s[x];
                s[x]=t;
                j++;
                x--;
            }
        }
        return s;
    }
};