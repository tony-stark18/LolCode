class Solution {
public:
    int modify(int num, const vector<int>& digMap) {
        if (num == 0) return digMap[0];
        int ans = 0, factor = 1;
        while (num > 0) {
            ans += digMap[num % 10] * factor;
            num /= 10;
            factor *= 10;
        }
        return ans;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> res(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            res[i] = {modify(nums[i], mapping), nums[i]};
        }

        sort(res.begin(), res.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first < p2.first;
        });

        vector<int> ans(nums.size());
        for (size_t i = 0; i < res.size(); ++i) {
            ans[i] = res[i].second;
        }

        return ans;
    }
};
