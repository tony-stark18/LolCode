class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Helper function to process the string and calculate the points
        auto process = [&](char first, char second, int points) {
            stack<char> st;
            int score = 0;
            for (char c : s) {
                if (!st.empty() && st.top() == first && c == second) {
                    score += points;
                    st.pop();
                } else {
                    st.push(c);
                }
            }
            // Convert stack to string to re-process remaining characters
            string remaining;
            while (!st.empty()) {
                remaining.push_back(st.top());
                st.pop();
            }
            reverse(remaining.begin(), remaining.end());
            return make_pair(score, remaining);
        };

        int totalScore = 0;

        // Process the string based on higher value pairs first
        if (x > y) {
            auto [score, remaining] = process('a', 'b', x);
            totalScore += score;
            s = remaining;
            tie(score, remaining) = process('b', 'a', y);
            totalScore += score;
        } else {
            auto [score, remaining] = process('b', 'a', y);
            totalScore += score;
            s = remaining;
            tie(score, remaining) = process('a', 'b', x);
            totalScore += score;
        }

        return totalScore;
    }
};
