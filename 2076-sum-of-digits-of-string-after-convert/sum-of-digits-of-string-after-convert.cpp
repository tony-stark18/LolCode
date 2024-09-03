class Solution {
public:
    int getSum(int n){
        int res = 0;
        while(n>0){
            res+=n%10;
            n/=10;
        }
        return res;
    }
    int getLucky(string s, int k) {
        string sum = "";
        for (char c : s) {
            sum += to_string(c -'a'+1);
        }
        int ans = 0;
        for(char c:sum){
            ans+=c-'0';
        }
        k--;
        while(k--){
           ans = getSum(ans);
        }
        return ans;
    }
};