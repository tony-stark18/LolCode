class Solution {
    public int findMaxLength(int[] nums) {
        HashMap<Integer,Integer> hs = new HashMap<>();
        int cSum = 0;
        hs.put(0,-1);
        int max = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>0){
                cSum++;
            }
            else{
                cSum--;
            }
            if(hs.containsKey(cSum)){
                max = Math.max(max,i-hs.get(cSum));
            }
            else{
                hs.put(cSum,i);
            }
        }
        return max;
    }
}