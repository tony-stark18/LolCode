class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        int n = nums.length;
        int res[] = new int[n];
        int k=0;
        int l=1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                res[k]=nums[i];
                k=k+2;
            }
            else{
                res[l]=nums[i];
                l=l+2;
            }
        }
        return res;
    }
}