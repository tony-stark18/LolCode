class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        HashMap<Integer,Integer> hs = new HashMap<>();
        hs.put(0,1);
        int sum = 0;
        int count = 0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            int rem = sum%k;
            if(rem<0) rem+=k;
            if(hs.containsKey(rem)){
                count+=hs.get(rem);
            }
            hs.put(rem,hs.getOrDefault(rem,0)+1);
        }
        return count;
    }
}