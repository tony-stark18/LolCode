class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (x > y) {
                if (!st.empty() && s[i] == 'b' && st.top() == 'a') {
                    ans += x;
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            } else  {
                if (!st.empty() && s[i] == 'a' && st.top() == 'b') {
                    ans += y;
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }
        vector<char> rmn;
        while (!st.empty()) {
            rmn.push_back(st.top());
            st.pop();
        }
        reverse(rmn.begin(),rmn.end());
        for(char c:rmn){
            cout<<c;
        }
        // cout<<st.size();
        for (int i = 0; i < rmn.size(); i++) {
            if (x > y) {
                if (!st.empty() && rmn[i] == 'a' && st.top() == 'b') {
                    ans += y;
                    st.pop();
                } else {
                    st.push(rmn[i]);
                }
            } else  {
                if (!st.empty() && rmn[i] == 'b' && st.top() == 'a') {
                    ans += x;
                    st.pop();
                } else {
                    st.push(rmn[i]);
                }
            }
        }
        return ans;
    }
};