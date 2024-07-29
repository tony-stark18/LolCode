class Solution {
    public int numTeams(int[] rating) {
        int n = rating.length;
        int count = 0;

        // Iterate over the middle soldier j
        for (int j = 1; j < n - 1; j++) {
            int leftLess = 0, leftGreater = 0;
            int rightLess = 0, rightGreater = 0;

            // Count soldiers on the left
            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j]) {
                    leftLess++;
                } else if (rating[i] > rating[j]) {
                    leftGreater++;
                }
            }

            // Count soldiers on the right
            for (int k = j + 1; k < n; k++) {
                if (rating[k] < rating[j]) {
                    rightLess++;
                } else if (rating[k] > rating[j]) {
                    rightGreater++;
                }
            }

            // Count valid teams
            count += leftLess * rightGreater + leftGreater * rightLess;
        }

        return count;
    }
}