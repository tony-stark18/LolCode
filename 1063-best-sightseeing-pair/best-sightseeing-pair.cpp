int IO = []{
    ios::sync_with_stdio(false); cin.tie(nullptr); return 0;
}();
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxSoFar = values[0]; 
        int ans = INT_MIN;
        for (int i = 1; i < values.size(); ++i) {
            ans = max(ans, maxSoFar + values[i] - i);
            maxSoFar = max(maxSoFar, values[i] + i);
        }
        return ans;
    }
};
