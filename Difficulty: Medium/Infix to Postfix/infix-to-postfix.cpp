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
            char ch = s[i];
            if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
                ans+=ch;
            }
            else if(ch=='(')
                st.push(ch);
            else if(ch==')'){
                while(!st.empty() && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop(); // Pop the '('
                }
            }
            else{
                while(!st.empty() && map[ch] <= map[st.top()]){
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
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