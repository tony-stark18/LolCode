class Solution {
    public long countSubarrays(int[] nums, int k) {
        int max = Integer.MIN_VALUE;
        for(int i:nums){
            max=Math.max(max,i);
        }
        int n = nums.length;
        int elCount = 0;
        long saCount = 0;
        int start = 0;
        for(int end = 0;end<n;end++){
            if(nums[end]==max) elCount++;
            while(elCount==k){
                if(nums[start]==max) elCount--;
                start++;
            }
            saCount+=start;
        }
        return saCount;
    }
}