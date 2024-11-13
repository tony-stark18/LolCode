#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lowerBound(const vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    int upperBound(const vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int left = i + 1;
            int minIdx = lowerBound(nums, left, n - 1, lower - nums[i]);
            int maxIdx = upperBound(nums, left, n - 1, upper - nums[i]);
            
            count += (maxIdx - minIdx);
        }
        
        return count;
    }
};
