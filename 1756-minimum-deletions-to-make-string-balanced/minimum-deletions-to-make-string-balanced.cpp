class Solution {
public:
    int minimumDeletions(string s) {
        int b_count = 0;       // Number of 'b's encountered so far
        int min_deletions = 0; // Minimum deletions needed to balance the string

        for (char ch : s) {
            if (ch == 'b') {
                b_count++;
            } else { // ch == 'a'
                // Either delete this 'a' or delete all previous 'b's seen so
                // far
                min_deletions = min(min_deletions + 1, b_count);
            }
        }

        return min_deletions;
    }
};