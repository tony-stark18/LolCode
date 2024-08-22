int IO = []{
    ios::sync_with_stdio(false); cin.tie(nullptr); return 0;
}();
class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int k = 0;
        while(num>0){
            int rem = num%2;
            if(rem==0) ans+=(int)pow(2,k);
            k++;
            num/=2;
        }
        return ans;
    }
};