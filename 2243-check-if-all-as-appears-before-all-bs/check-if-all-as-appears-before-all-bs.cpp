class Solution {
public:
    bool checkString(string s) {
        int b_count = 0;
        for(char ch:s){
            if(ch=='b') b_count++;
            if(ch=='a' && b_count>0) return false;
        }
        return true;
    }
};