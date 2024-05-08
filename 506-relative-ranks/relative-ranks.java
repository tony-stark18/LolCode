class Solution {
    public String[] findRelativeRanks(int[] score) {
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (int i = 0; i < score.length; i++) {
            maxHeap.add(new int[]{score[i], i});
        }
        String[] ans = new String[score.length];
        int k = 1;
        while (!maxHeap.isEmpty()) {
            int[] pair = maxHeap.poll();
            int ind = pair[1];
            if (k == 1) {
                ans[ind] = "Gold Medal";
            } else if (k == 2) {
                ans[ind] = "Silver Medal";
            } else if (k == 3) {
                ans[ind] = "Bronze Medal";
            } else {
                ans[ind] = String.valueOf(k);
            }
            k++;
        }
        return ans;
    }
}
