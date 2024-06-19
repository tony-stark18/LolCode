class Solution {
public:
    int helper(vector<int>& bloomDay, int day, int k) {
        int bqt = 0;
        int flower = 0;
        for (int i : bloomDay) {
            if (i <= day) {
                flower++;
                if (flower == k) {
                    bqt++;
                    flower = 0;
                }
            } else {
                flower = 0;
            }
        }
        return bqt;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        if (helper(bloomDay, high, k) < m) return -1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (helper(bloomDay, mid, k) >= m) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
