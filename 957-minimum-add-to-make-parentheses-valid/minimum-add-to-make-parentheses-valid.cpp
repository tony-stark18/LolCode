class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int count = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(')
                balance++;
            else {
                if (balance > 0) {
                    balance--;
                }
                else{
                    count++;
                    balance=0;
                }
            }
        }
        return balance+count;
    }
};