class Solution {
public:
    int calc(vector<int>& weights, int capacity) {
        int load = 0;
        int days = 0;
        for(int i:weights){
            if(load+i<=capacity){
                load+=i;
            }
            else{
                days++;
                load = i;
            }
        }
        return days+1;
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