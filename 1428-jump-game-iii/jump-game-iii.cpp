class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        vector<int> vis(arr.size(),0);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            if(arr[t]==0) return true;
            if((t+arr[t])<arr.size() && !vis[t+arr[t]]){
                vis[t+arr[t]]=1;
                q.push(t+arr[t]);
            }
            if(t-arr[t]>=0 && !vis[t-arr[t]]){
                vis[t-arr[t]]=1;
                q.push(t-arr[t]);
            }
        }
        return false;
    }
};