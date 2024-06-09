class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> hs = new HashMap<>();
        int count = 0;
        int sum = 0;
        hs.put(0,1);
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            int rem = sum-k;
            count+=hs.getOrDefault(rem,0);
            hs.put(sum,hs.getOrDefault(sum,0)+1);
        }
        return count;
    }
}