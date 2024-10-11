class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        priority_queue<int, vector<int>, greater<int>> chairs;
     
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (int i = 0; i < n; i++) {
            times[i].push_back(i); 
        }

        sort(times.begin(), times.end());

        for (int i = 0; i < n; i++) {
            chairs.push(i);
        }

        for (int i = 0; i < n; i++) {
            int at = times[i][0];        
            int lt = times[i][1];        
            int friendIdx = times[i][2]; 

            
            while (!pq.empty() && pq.top().first <= at) {
                chairs.push(pq.top().second); 
                pq.pop();
            }

            int chairIndex = chairs.top();
            chairs.pop();

            if (friendIdx == targetFriend) {
                return chairIndex;
            }

            pq.push({lt, chairIndex});
        }

        return -1;
    }
};
