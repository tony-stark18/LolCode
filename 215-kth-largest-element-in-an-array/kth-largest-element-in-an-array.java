class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pQ = new PriorityQueue<>();
        for(int i:nums){
            pQ.add(i);
            if(pQ.size()>k) pQ.remove();
        }
        return pQ.remove();
    }
}