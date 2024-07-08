class Solution {
    public static int findTheWinner(int n, int k) {
        int winner = 0; // Initialize winner's position (zero-indexed)

        // Iterate over each number from 2 to n
        for (int i = 2; i <= n; i++) {
            winner = (winner + k) % i;
        }

        // Convert zero-indexed position to one-indexed
        return winner + 1;
    }
}