class Solution {
    public int removeDuplicates(int[] nums) {
        int frq = 1;
        int cnt = 1;
        for(int i=1;i<nums.length;i++){
            if(nums[i]!=nums[i-1]){
                frq=1;
                nums[cnt] = nums[i];
                cnt++;
            }
            else if(frq<2){
                nums[cnt] = nums[i];
                cnt++;
                frq++;
            }
        }
        return cnt;
    }
}