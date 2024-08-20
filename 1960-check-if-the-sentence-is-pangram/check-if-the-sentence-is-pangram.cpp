class Solution {
    public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> set;
        for(char c:sentence){
            set.insert(c);
        }
        for(char c='a';c<='z';c++){
            if(set.find(c)==set.end()) return false;
        }
        return true;
    }
};