class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int n = nums.length;
        int arr[] = new int[n+1];
        arr[0]=1;
        int count=0;
        int sum=0;
        for(int i:nums){
            sum+=i;
            if(sum>=goal){
                count+=arr[sum-goal];
            }
            arr[sum]++;
        }
        return count;
    }
}