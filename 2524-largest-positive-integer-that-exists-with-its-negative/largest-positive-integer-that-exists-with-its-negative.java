class Solution {
    public int findMaxK(int[] nums) {
        HashMap<Integer,Integer> hs = new HashMap<>();
        int max = -1;
        for(int i:nums){
            if(hs.containsKey(-i)){
                max=Math.max(Math.abs(i),max);
            }
            hs.put(i,1);
        }
        return max;
    }
}