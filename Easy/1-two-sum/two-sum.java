class Solution {
    public int[] twoSum(int[] nums, int target) {
        int arr[] = new int[2];
        HashMap<Integer,Integer> hs = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(hs.containsKey(target-nums[i])){
                arr[0] = hs.get(target-nums[i]);
                arr[1] = i;
                break;
            }
            else{
                hs.put(nums[i],i);
            }
        }
        return arr;
    }
}