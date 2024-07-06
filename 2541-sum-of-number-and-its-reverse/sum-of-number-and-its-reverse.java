class Solution {
    public int rev(int num){
        int res=0;
        while(num>0){
            res=res*10+num%10;
            num/=10;
        }
        return res;
    }
    public boolean sumOfNumberAndReverse(int num) {
        if(num==0) return true;
        for(int i=num/2;i<=num;i++){
            if(i+rev(i)==num) return true;
        }
        return false;
    }
}