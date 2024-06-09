class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int freq[] = new int[k];
        freq[0]=1;
        int sum = 0;
        int count = 0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            int rem = sum%k;
            if(rem<0) rem+=k;
            if(freq[rem]>0){
                count+=freq[rem];
            }
            freq[rem]++;
        }
        return count;
    }
}