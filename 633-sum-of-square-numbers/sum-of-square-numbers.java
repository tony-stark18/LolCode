class Solution {

    public boolean judgeSquareSum(int c) {
        int right = (int) Math.sqrt(c);
        int left = 0;
        while(left<=right){
            long prod = (long) left * left + (long) right * right;
            if(prod==c) return true;
            else if(prod>c) right--;
            else left++;
        }
        return false;
    }
}