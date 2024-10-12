class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<int,vector<int>,greater<int>> chairs;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n = times.size();
        for(int i=0;i<n;i++){
            times[i].push_back(i);
            chairs.push(i);
        }
        sort(times.begin(),times.end());
        for(int i=0;i<n;i++){
            int at = times[i][0];
            int lt = times[i][1];
            int oi = times[i][2];

            while(!pq.empty() && pq.top().first<=at){
                chairs.push(pq.top().second);
                pq.pop();
            }

            int avail_chair = chairs.top();
            if(oi==targetFriend) return avail_chair;
            pq.push({lt,avail_chair});
            chairs.pop();
        }
        return -1;
    }
};