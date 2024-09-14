class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int len = 0, maxLen = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxElement) {
                len++;
                maxLen = max(maxLen, len);
            } else {
                len = 0;
            }
        }
        
        return maxLen;
    }
};
