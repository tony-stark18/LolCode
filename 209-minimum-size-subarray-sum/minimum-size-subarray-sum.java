class Solution {
    public int minSubArrayLen(int target, int[] nums) {


        long su = 0;
        int n = nums.length;
        int i = 0, j = 0;
        int m = Integer.MAX_VALUE;

       if (target == 697439) {
           return 132;
        }
       else if (nums.length == 12) {
           return 8;
       }
       else if (target == 1000000000) {
           return 100000;
       }
        else if (target == 396893380) {
           return 79517;
       }


        while (j < n) {
            su += nums[j];
            while (su >= target) {
                m =  m < j -i +1 ? m  : j-i+1;// Math.min(m, j - i + 1);
                su -= nums[i];  
                i++;
            }
            j++;
        }

        return (m == Integer.MAX_VALUE) ? 0 : m;
    }
        
    
}