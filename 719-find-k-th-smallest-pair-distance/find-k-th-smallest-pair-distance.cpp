class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> distanceBucket(maxElement + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int distance = abs(nums[i] - nums[j]);
                ++distanceBucket[distance];
            }
        }
        for (int i = 0; i < distanceBucket.size(); i++) {
            k -= distanceBucket[i];
            if (k <= 0)
                return i;
        }
        return -1;
    }
};