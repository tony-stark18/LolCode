class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                
                if (token == "+") st.push(num2 + num1);
                else if (token == "-") st.push(num2 - num1);
                else if (token == "*") st.push(num2 * num1);
                else if (token == "/") st.push(num2 / num1);
                
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
