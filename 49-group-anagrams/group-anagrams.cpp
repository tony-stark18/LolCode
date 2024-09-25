class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (const string& s : strs) {
            string temp = s;                
            sort(temp.begin(), temp.end());
            map[temp].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto it : map) {
            // cout << it.first << " " << it.second;
            ans.push_back(it.second);
        }
        return ans;
    }
};