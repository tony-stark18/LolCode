class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st(allowed.begin(),allowed.end());
        int count = 0;
        for(string word:words){
            bool flag = true;
            for(char c:word){
                if(st.find(c)==st.end()){
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        } 
        return count;
    }
};