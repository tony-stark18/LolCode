class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        HashMap<Integer,Integer> hs = new HashMap<>();
        hs.put(0,1);
        int count = 0;
        int sum = 0;
        for(int i:nums){
            sum+=i;
            if(hs.containsKey(sum-goal)) count+=hs.get(sum-goal);
            hs.put(sum,hs.getOrDefault(sum,0)+1);
        }
        return count;
    }
}