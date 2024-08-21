class Solution {
public:
    int strangePrinter(string s) {
        // Preprocess the string to remove consecutive duplicate characters
        s = removeDuplicates(s);
        int n = s.length();
        // Initialize memoization array
        vector<vector<int>> memo(n, vector<int>(n, -1));
        // Start the recursive process
        return minimumTurns(0, n - 1, s, memo);
    }

private:
    int minimumTurns(int start, int end, string& s, vector<vector<int>>& memo) {
        if (start > end) {
            return 0;
        }
        cout<<start<<end<<",";
        if (memo[start][end] != -1) {
            return memo[start][end];
        }

        int minTurns = 1 + minimumTurns(start + 1, end, s, memo);

        for (int k = start + 1; k <= end; k++) {
            if (s[k] == s[start]) {
                int turnsWithMatch = minimumTurns(start, k - 1, s, memo) +
                                     minimumTurns(k + 1, end, s, memo);
                // cout<<"Inner"<<turnsWithMatch<<" ";
                minTurns = min(minTurns, turnsWithMatch);
            }
        }

        return memo[start][end] = minTurns;
    }

    string removeDuplicates(string& s) {
        string uniqueChars;
        int i = 0;
        while (i < s.length()) {
            char currentChar = s[i];
            uniqueChars += currentChar;
            while (i < s.length() && s[i] == currentChar) {
                i++;
            }
        }
        return uniqueChars;
    }
};