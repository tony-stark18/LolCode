class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxSoFar = values[0]; // Initialize with the first element (values[0] + 0)
        int ans = INT_MIN;

        for (int i = 1; i < values.size(); ++i) {
            // Calculate the current max sightseeing score
            ans = max(ans, maxSoFar + values[i] - i);

            // Update maxSoFar for the next iteration
            maxSoFar = max(maxSoFar, values[i] + i);
        }

        return ans;
    }
};
