class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        int max_ramp = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                st.push(i);
                continue;
            }
            if (nums[i] > nums[st.top()]) {
                st.push(i);
            } else {
                stack<int> temp;
                int ramp = 0;
                while(!st.empty() && nums[st.top()]>=nums[i]){
                    ramp = st.top()-i;
                    temp.push(st.top());
                    st.pop();
                }
                while(!temp.empty()){
                    st.push(temp.top());
                    temp.pop();
                }
                max_ramp = max(ramp,max_ramp);
            }
        }
        return max_ramp;
    }
};