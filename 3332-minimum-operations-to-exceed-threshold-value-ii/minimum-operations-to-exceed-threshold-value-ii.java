class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        for(int n:nums){
            pq.offer((long)n);
        }
        int ans= 0;
        while(true){
            if(pq.peek()>=k){
                break;
            }
            long a = pq.poll();
            long b = pq.poll();
            pq.offer(Math.min(a,b)*2+Math.max(a,b));
            ans++;
        }   
        return ans;
    }
}