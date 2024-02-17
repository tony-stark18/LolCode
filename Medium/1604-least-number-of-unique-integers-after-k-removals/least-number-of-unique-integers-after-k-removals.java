import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        int n = arr.length;
        Map<Integer, Integer> hm = new HashMap<>();
        for (int i = 0; i < n; i++) {
            hm.put(arr[i], hm.getOrDefault(arr[i], 0) + 1);
        }

        PriorityQueue<Integer> minHeap = new PriorityQueue<>(hm.values());
        int uniqueCount = minHeap.size();

        while (!minHeap.isEmpty() && k > 0) {
            int frequency = minHeap.poll();
            k -= frequency;

            if (k >= 0) {
                uniqueCount--;
            }
        }

        return uniqueCount;
    }
}
