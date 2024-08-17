class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<long long> prev(n, 0);
        
        // Initialize the previous row with the first row's points
        for (int j = 0; j < n; ++j) {
            prev[j] = points[0][j];
        }

        // Iterate through each row, updating the dp array
        for (int i = 1; i < m; ++i) {
            vector<long long> leftMax(n, 0), rightMax(n, 0), curr(n, 0);
            
            // Compute leftMax for the current row
            leftMax[0] = prev[0];
            for (int j = 1; j < n; ++j) {
                leftMax[j] = max(leftMax[j - 1], prev[j] + j);
            }
            
            // Compute rightMax for the current row
            rightMax[n - 1] = prev[n - 1] - (n - 1);
            for (int j = n - 2; j >= 0; --j) {
                rightMax[j] = max(rightMax[j + 1], prev[j] - j);
            }
            
            // Compute the current row dp using leftMax and rightMax
            for (int j = 0; j < n; ++j) {
                curr[j] = points[i][j] + max(leftMax[j] - j, rightMax[j] + j);
            }
            
            // Move to the next row
            prev = curr;
        }

        // The answer will be the maximum value in the last computed row
        return *max_element(prev.begin(), prev.end());
    }
};
