class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        vector<pair<int, char>> psn;
        unordered_map<int, int> hlth;
        for (int i = 0; i < positions.size(); i++) {
            psn.push_back({positions[i], directions[i]});
            hlth[positions[i]] = healths[i];
        }
        sort(psn.begin(), psn.end());
        stack<pair<int, char>> st;
        for (auto it : psn) {
            if (!st.empty() && it.second == 'L' && st.top().second == 'R') {
                while (!st.empty() && it.second == 'L' && st.top().second == 'R') {
                    int healthR = hlth[st.top().first];
                    int healthL = hlth[it.first];
                    if (healthR == healthL) {
                        hlth.erase(st.top().first);
                        hlth.erase(it.first);
                        st.pop();
                        break;
                    } else if (healthR > healthL) {
                        hlth.erase(it.first);
                        hlth[st.top().first]--;
                        break;
                    } else {
                        hlth.erase(st.top().first);
                        hlth[it.first]--;
                        st.pop();
                    }
                }
                if (it.second == 'L' && (st.empty() || st.top().second != 'R')) {
                    st.push(it);
                }
            } else {
                st.push(it);
            }
        }
        vector<int> ans;
        for (int i : positions) {
            if (hlth.find(i) != hlth.end())
                ans.push_back(hlth[i]);
        }
        return ans;
    }
};
