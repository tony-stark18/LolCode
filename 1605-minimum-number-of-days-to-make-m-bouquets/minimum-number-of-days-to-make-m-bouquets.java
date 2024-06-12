class Solution {
    // Helper function to calculate the number of bouquets that can be made by `day`
    public int helper(int[] arr, int k, int day) {
        int count = 0;
        int bcount = 0;
        for (int i : arr) {
            if (i <= day) {
                count++;
                if (count == k) {
                    bcount++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return bcount;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        int n = bloomDay.length;
        if ((long)m * k > (long)n) return -1;

        int minDay = Integer.MAX_VALUE;
        int maxDay = Integer.MIN_VALUE;

        // Determine the minimum and maximum bloom days
        for (int i : bloomDay) {
            minDay = Math.min(minDay, i);
            maxDay = Math.max(maxDay, i);
        }

        // Binary search for the minimum number of days
        while (minDay <= maxDay) {
            int midDay = minDay + (maxDay - minDay) / 2;
            int bcount = helper(bloomDay, k, midDay);

            if (bcount >= m) {
                maxDay = midDay - 1;
            } else {
                minDay = midDay + 1;
            }
        }
        return minDay;
    }
}
