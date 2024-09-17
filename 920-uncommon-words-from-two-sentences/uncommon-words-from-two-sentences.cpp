class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> map;
        int ptr = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == ' ') {
                map[s1.substr(ptr, i - ptr)]++;
                ptr = i + 1;
            }
        }
        map[s1.substr(ptr, s1.length() - ptr)]++;
        ptr = 0;
        for (int i = 0; i < s2.length(); i++) {
            if (s2[i] == ' ') {
                map[s2.substr(ptr, i - ptr)]++;
                ptr = i + 1;
            }
        }
        map[s2.substr(ptr, s2.length() - ptr)]++;
        vector<string> ans;
        for (auto it : map) {
            if(it.second==1) ans.push_back(it.first);
        }
        return ans;
    }
};