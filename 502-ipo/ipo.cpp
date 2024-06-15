class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        priority_queue<int> maxprof ;
        for(int i=0;i<n;i++){
            pq.push({capital[i],profits[i]});
        }
        while(k--){
            while(!pq.empty() && pq.top().first<=w){
                maxprof.push(pq.top().second);
                pq.pop();
            }
            if(maxprof.empty()) break;
            w+=maxprof.top();
            maxprof.pop();
        }
        return w;
    }
};