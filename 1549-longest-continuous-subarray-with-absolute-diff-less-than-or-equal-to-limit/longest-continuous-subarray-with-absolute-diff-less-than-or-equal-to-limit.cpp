#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int left = 0, right = 0;
        int ans = 0;
        int minv = nums[0], maxV = nums[0];

        while (right < n) {
            minv = min(minv, nums[right]);
            maxV = max(maxV, nums[right]);

            if (maxV - minv <= limit) {
                ans = max(ans, right - left + 1);
                right++;
            } else {
                left++;
                minv = nums[left];
                maxV = nums[left];
                for (int i = left; i <= right; i++) {
                    minv = min(minv, nums[i]);
                    maxV = max(maxV, nums[i]);
                }
                right++;
            }
        }

        return ans;
    }
};
