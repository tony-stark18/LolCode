class Solution {
public:
    bool rotateString(string original, string pattern) {
        if(original.length()!=pattern.length()) return false;
        original += original;
        if (original.find(pattern) != string::npos) {
            return true;
        }
        return false;
    }
};