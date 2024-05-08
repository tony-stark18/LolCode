class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> maxHeap;
        for(int i=0;i<score.size();i++){
            maxHeap.push({score[i],i});
        }
        vector<string> ans(score.size(),"");
        if(!maxHeap.empty()){
            ans[maxHeap.top().second]="Gold Medal";
            maxHeap.pop();
        }
        if(!maxHeap.empty()){
            ans[maxHeap.top().second]="Silver Medal";
            maxHeap.pop();
        }
        if(!maxHeap.empty()){
            ans[maxHeap.top().second]="Bronze Medal";
            maxHeap.pop();
        }
        int k = 4;
        while(!maxHeap.empty()){
            int ind = maxHeap.top().second;
            maxHeap.pop();
            ans[ind]=to_string(k);
            k++;
        }
        return ans;
    }
};