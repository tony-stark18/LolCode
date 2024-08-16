class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int ans = INT_MIN;
        int minV = arrays[0][0];
        int maxV = arrays[0].back();
        for(int i=1;i<n;i++){
            ans = max(ans,abs(arrays[i].back()-minV));
            ans = max(ans,abs(arrays[i][0]-maxV));

            minV = min(minV,arrays[i][0]);
            maxV = max(maxV,arrays[i].back());
        }
        return ans;
    }
};