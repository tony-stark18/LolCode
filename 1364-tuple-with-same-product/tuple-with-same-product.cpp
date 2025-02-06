static const int _ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                map[nums[i] * nums[j]]++;
            }
        }
        int ans = 0;
        for (auto it : map) {
            int freq = it.second;
            int combination = freq * (freq - 1) / 2;
            ans += (combination * 8);
            cout << ans << " ";
        }
        return ans;
    }
};