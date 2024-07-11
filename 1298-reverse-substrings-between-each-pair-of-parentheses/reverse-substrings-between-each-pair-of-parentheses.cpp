class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                vector<char> temp;
                while(st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(char c:temp){
                    st.push(c);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ss;
        while(!st.empty()){
            ss+=st.top();
            st.pop();
        }
        reverse(ss.begin(),ss.end());
        return ss;
    }
};