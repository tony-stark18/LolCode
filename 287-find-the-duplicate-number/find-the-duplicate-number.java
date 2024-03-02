class Solution {
    public int findDuplicate(int[] nums) {
        int n = nums.length;
        boolean freq[] = new boolean[n];
        for(int i=0;i<n;i++){
            if(freq[nums[i]]) return nums[i];
            freq[nums[i]]=true;
        }
        return -1;
    }
}