import java.util.PriorityQueue;

class Solution {
    class Pair implements Comparable<Pair> {
        int score;
        int index;

        public Pair(int score, int index) {
            this.score = score;
            this.index = index;
        }

        @Override
        public int compareTo(Pair other) {
            return other.score - this.score; // Sort in descending order of scores
        }
    }

    public String[] findRelativeRanks(int[] score) {
        PriorityQueue<Pair> maxHeap = new PriorityQueue<>();
        for (int i = 0; i < score.length; i++) {
            maxHeap.add(new Pair(score[i], i));
        }

        String[] ans = new String[score.length];
        int rank = 1;
        while (!maxHeap.isEmpty()) {
            Pair pair = maxHeap.poll();
            int index = pair.index;
            if (rank == 1) {
                ans[index] = "Gold Medal";
            } else if (rank == 2) {
                ans[index] = "Silver Medal";
            } else if (rank == 3) {
                ans[index] = "Bronze Medal";
            } else {
                ans[index] = String.valueOf(rank);
            }
            rank++;
        }
        return ans;
    }
}
