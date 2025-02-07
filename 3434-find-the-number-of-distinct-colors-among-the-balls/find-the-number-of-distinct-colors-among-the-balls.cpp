class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> balls;
        unordered_map<int,int> colors;
        vector<int> ans;
        for(auto it:queries){
            if(balls.find(it[0])!=balls.end()){
                int ball = balls[it[0]];
                colors[ball]--;
                if(colors[ball]==0){
                    colors.erase(ball);
                }
                balls[it[0]]=it[1];
            } else{
                balls[it[0]]=it[1];
            }
            colors[it[1]]++;
            cout<<colors.size()<<" ";
            ans.push_back(min(colors.size(),balls.size()));
        }
        return ans;
    }
};