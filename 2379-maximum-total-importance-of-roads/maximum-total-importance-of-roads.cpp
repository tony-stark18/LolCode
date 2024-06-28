class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        priority_queue<pair<int,int>> pq;
        vector<int> nodes(n,0);
        for(auto it:roads){
            nodes[it[0]]++;
            nodes[it[1]]++;
        }
        for(int i=0;i<n;i++){
            pq.push({nodes[i],i});
        }
        while(!pq.empty()){
            auto pair = pq.top();
            pq.pop();
            nodes[pair.second]=n--;
        }
        long long ans = 0;
        for(auto it:roads){
            ans+=nodes[it[0]]+nodes[it[1]];
        }
        return ans;
    }
};