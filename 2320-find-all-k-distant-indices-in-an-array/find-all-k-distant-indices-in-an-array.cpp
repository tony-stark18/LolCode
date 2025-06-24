class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                for (int j = 0; j <= k; j++) {
                    if (i - j>=0) {
                        st.insert(i - j);
                    }
                    st.insert(i);
                    if(i+j<nums.size()) st.insert(i + j);
                }
            }
        }
        vector<int> ans;
        for (auto it : st)
            ans.push_back(it);
        sort(ans.begin(),ans.end());
        return ans;
    }
};