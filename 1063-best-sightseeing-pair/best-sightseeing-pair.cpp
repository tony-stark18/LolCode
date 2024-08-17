class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<int> secondMax(values.size());
        int sMax = INT_MIN;
        for(int i=values.size()-1;i>=0;i--){
            sMax = max(sMax,values[i]-i);
            secondMax[i]=sMax;
        }
        int fMax = INT_MIN;
        int ans = INT_MIN;
        for(int i=0;i<values.size()-1;i++){
            fMax = max(fMax,values[i]+i);
            ans = max(ans,fMax+secondMax[i+1]);
        }
        return ans;
    }
};