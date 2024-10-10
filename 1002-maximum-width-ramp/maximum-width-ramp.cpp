class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        int max_ramp = 0;
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            int ramp = 0;
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                ramp = i - st.top();
                st.pop();
            }
            max_ramp = max(ramp, max_ramp);
        }
        return max_ramp;
    }
};