class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<int> freqs(100001, 0);
        long long ans = 0, sum = 0;
        int l = 0, r = 0;

        while (r < nums.size()) {
            if (freqs[nums[r]] > 0) {
                sum -= nums[l];
                freqs[nums[l]]--;
                l++;
            } else {
                sum += nums[r];
                freqs[nums[r]]++;
                r++;

                if (r - l == k) {
                    ans = max(ans, sum);
                    sum -= nums[l];
                    freqs[nums[l]]--;
                    l++;
                }
            }
        }
        return ans;
    }
};
