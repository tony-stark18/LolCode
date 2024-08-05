class Solution {
public:
    string kthDistinct(const vector<string>& arr, int k) {
        unordered_map<string, int> map;
        for (const auto& it : arr) {
            map[it]++;
        }
        for (const auto& it : arr) {
            if (map[it] == 1) {
                k--;
                if (k == 0) {
                    return it;
                }
            }
        }
        return "";
    }
};
