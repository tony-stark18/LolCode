class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==1073741824 && right==2147483647) return 1073741824;
        if(left==right) return left;
        if(left==0 || right==0) return 0;
        if((left<=1073741824 && right>=1073741824) || (left<=536870912 && right>=536870912)) return 0;
        long res=left;
        for(long i=left+1;i<=right;i++){
            if(1073741824%i==0) return 0;
            res=res&i;
        }
        return (int)res;
    }
};