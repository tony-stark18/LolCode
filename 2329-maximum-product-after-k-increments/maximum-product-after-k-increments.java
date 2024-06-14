import java.util.PriorityQueue;

class Solution {
    public int maximumProduct(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i : nums) {
            pq.offer(i);
        }
        
        while (k > 0) {
            int smallest = pq.poll();
            pq.offer(smallest + 1);
            k--;
        }
        
        long prod = 1;
        int MOD = 1_000_000_007;
        
        while (!pq.isEmpty()) {
            prod = (prod * pq.poll()) % MOD;
        }
        
        return (int) prod;
    }
}
