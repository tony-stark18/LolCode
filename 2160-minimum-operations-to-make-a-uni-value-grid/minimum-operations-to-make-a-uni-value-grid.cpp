class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int m = grid.size(), n = grid[0].size();
        
        for (auto& row : grid) {
            for (int num : row) {
                arr.push_back(num);
            }
        }

        int size = m * n;
        nth_element(arr.begin(), arr.begin() + size / 2, arr.end());
        int pivot = arr[size / 2];

        int ans = 0;
        for (int num : arr) {
            if ((num - pivot) % x != 0) return -1;
            ans += abs(num - pivot) / x;
        }
        return ans;
    }
};
