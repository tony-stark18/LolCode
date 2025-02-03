int IO = []{
    ios::sync_with_stdio(false); cin.tie(nullptr); return 0;
}();
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeSlots;
        int n = startTime.size();
        freeSlots.push_back(startTime[0]);
        for(int i=1;i<n;i++){
            freeSlots.push_back(startTime[i]-endTime[i-1]);
        }
        freeSlots.push_back(eventTime-endTime[n-1]);
        int windowSize = k+1;
        n = freeSlots.size();
        int sum = 0;
        for(int i=0;i<windowSize;i++){
            if(i<n){
                sum+=freeSlots[i];
            }
        }
        int ans=sum;
        for(int i=windowSize;i<n;i++){
            sum = sum-freeSlots[i-windowSize]+freeSlots[i];
            ans = max(ans,sum);
        }
        return ans;
    }
};