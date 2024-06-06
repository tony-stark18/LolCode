class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        Arrays.sort(nums);
        HashMap<Integer,Integer> hs = new HashMap<>();
        for(int num:nums){
            hs.put(num,hs.getOrDefault(num,0)+1);
        }
        for(int num:nums){
            if(hs.get(num)==0) continue;
            for(int i=0;i<k;i++){
                int curr = num+i;
                if(hs.getOrDefault(curr,0)==0) return false;
                hs.put(curr,hs.get(curr)-1);
            }
        }
        return true;
    }
}