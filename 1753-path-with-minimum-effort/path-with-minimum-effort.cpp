class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> difference(m,vector<int>(n,1e9));
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        difference[0][0]=0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int curr_diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r==m-1 && c==n-1){
                return curr_diff;
            }
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && difference[nr][nc]>max(curr_diff,abs(heights[r][c]-heights[nr][nc]))){
                    pq.push({max(curr_diff,abs(heights[r][c]-heights[nr][nc])),{nr,nc}});
                    difference[nr][nc]=max(curr_diff,abs(heights[r][c]-heights[nr][nc]));
                }
            }
        }
        return 0;
    }
};