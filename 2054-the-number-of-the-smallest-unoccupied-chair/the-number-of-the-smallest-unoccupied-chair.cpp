class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> chairs(n, -1); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        
        for (int i = 0; i < n; i++) {
            times[i].push_back(i); 
        }

        sort(times.begin(), times.end());

        for (int i = 0; i < n; i++) {
            int at = times[i][0];        
            int lt = times[i][1];       
            int friendIdx = times[i][2]; 

            while (!pq.empty() && pq.top().first <= at) {
                chairs[pq.top().second] = -1; 
                pq.pop();
            }

            int chairIndex = -1;
            for (int j = 0; j < n; j++) {
                if (chairs[j] == -1) {
                    chairs[j] = friendIdx;
                    chairIndex = j;
                    if (friendIdx == targetFriend) {
                        return j;
                    }
                    break;
                }
            }
            pq.push({lt, chairIndex});
        }

        return -1;
    }
};
