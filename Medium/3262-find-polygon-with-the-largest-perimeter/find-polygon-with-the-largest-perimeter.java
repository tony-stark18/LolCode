class Solution {
    public long largestPerimeter(int[] nums) {
        int n = nums.length;
        if(n<3) return -1;
        Arrays.sort(nums);
        long sum=0;
        for(int i=0;i<n-1;i++){
            sum+=nums[i];
        }
        System.out.println(sum);
        for(int i=n-1;i>=0;i--){
            if(nums[i]<sum && i>=2){
                return sum+nums[i];
            }
            if(i<2){
                return -1;
            }
            sum=sum-nums[i-1];

        }
        return sum;
    }
}