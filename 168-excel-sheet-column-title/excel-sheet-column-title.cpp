class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while (columnNumber > 0) {
            columnNumber--; // Adjust to 0-based indexing
            char c = 'A' + columnNumber % 26;
            result = c + result;
            columnNumber /= 26;
        }

        return result;
    }
};