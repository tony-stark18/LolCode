class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = -1;
        int diff = INT_MAX;
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    ans = sum;
                }
                if (sum < target) {
                    j++;
                } else if (sum > target) {
                    k--;
                } else
                    return sum;
            }
        }
        return ans;
    }
};