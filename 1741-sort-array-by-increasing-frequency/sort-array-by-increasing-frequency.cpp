class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> map;
        for (int i : nums) {
            map[i]++;
        }
        vector<pair<int, int>> temp;
        for (auto it : map) {
            temp.push_back({it.second, it.first});
        }
        sort(temp.begin(), temp.end(),
             [](const pair<int, int>& p1, const pair<int, int>& p2) {
                 if (p1.first == p2.first)
                     return p1.second > p2.second;
                 return p1.first < p2.first;
             });
        for (auto it : temp) {
            cout << it.first << "->" << it.second << " ";
            while (map[it.second]--) {
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};