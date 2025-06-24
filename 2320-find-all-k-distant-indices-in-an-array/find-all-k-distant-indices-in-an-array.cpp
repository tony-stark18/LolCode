class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> mark(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                int l = max(0, i - k);
                int r = min(n - 1, i + k);
                mark[l]++;
                mark[r + 1]--;
            }
        }

        vector<int> ans;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            count += mark[i];
            if (count > 0) ans.push_back(i);
        }

        return ans;
    }
};
