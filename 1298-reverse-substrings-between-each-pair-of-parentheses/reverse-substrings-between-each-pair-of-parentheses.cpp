class Solution {
public:
    string reverseParentheses(string s) {
        vector<deque<char>> deques(1);  // A list of deques to handle nested parentheses
        for (char c : s) {
            if (c == '(') {
                deques.emplace_back();  // Start a new deque for the new level of nested parentheses
            } else if (c == ')') {
                deque<char> temp = move(deques.back());
                deques.pop_back();
                copy(temp.rbegin(), temp.rend(), back_inserter(deques.back()));
            } else {
                deques.back().push_back(c);
            }
        }
        // Combine all characters from the deque into the final string
        string result;
        for (char c : deques[0]) {
            result.push_back(c);
        }
        return result;
    }
};
