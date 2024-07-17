//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        stack<char> st;
        unordered_map<char,int> map;
        map['^'] = 3;
        map['*'] = 2;
        map['/'] = 2;
        map['+'] = 1;
        map['-'] = 1;
        string ans = "";
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')){
                ans+=c;
            }
            else if(c=='('){
                st.push(c);
            }
            else if(c==')'){
                while(st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && map[c]<=map[st.top()]){
                    ans+=st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends