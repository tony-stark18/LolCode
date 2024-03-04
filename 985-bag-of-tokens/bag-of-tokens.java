import java.util.Arrays;

class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        if (tokens.length == 0) {
            return 0;
        }

        int score = 0;
        int maxScore = 0;
        int left = 0;
        int n = tokens.length;
        int right = n - 1;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (tokens[j] > tokens[j + 1]) {
                    int temp = tokens[j];
                    tokens[j] = tokens[j + 1];
                    tokens[j + 1] = temp;
                }
            }
        }

        if (power < tokens[left]) {
            return 0;
        }
        
        while (left <= right) {
            while (left <= right && power >= tokens[left]) {
                score++;
                power -= tokens[left];
                left++;
            }

            if (score == 0) return maxScore;

            maxScore = Math.max(score, maxScore);

            if (score > 0) {
                score--;
                power += tokens[right];
                right--;
                maxScore = Math.max(score, maxScore);
            }
        }

        return maxScore;
    }
}
