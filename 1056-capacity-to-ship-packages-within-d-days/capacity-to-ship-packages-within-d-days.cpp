class Solution {
public:
    int calc(vector<int>& weights, int capacity) {
        int days = 1; // At least one day is needed
        int current_load = 0;

        for (int weight : weights) {
            if (current_load + weight > capacity) {
                // Start a new day if the current load exceeds the capacity
                days++;
                current_load = 0;
            }
            current_load += weight;
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int required_days = calc(weights, mid);

            if (required_days <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};