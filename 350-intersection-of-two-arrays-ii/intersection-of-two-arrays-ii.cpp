class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> nums1_cnt;
        for (int num : nums1) {
            nums1_cnt[num]++;
        }
        std::vector<int> ans;
        for (int num : nums2) {
            if (nums1_cnt.contains(num)) {
                ans.push_back(num);
                if (--nums1_cnt[num] == 0) {
                    nums1_cnt.erase(num);
                }
            }
        }
        return ans;
    }
};