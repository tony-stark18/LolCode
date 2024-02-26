class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dis(m,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dis[0][0] = 0;
        pq.push({0,{0,0}});
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int dif = pq.top().first;
            pq.pop();

            if(row==m-1 && col == n-1) return dif;
            for(int i=0; i<4; i++) {
                    
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int newEffort = max(abs(grid[nr][nc]-grid[row][col]),dif);
                    if (newEffort < dis[nr][nc])
                    {
                        dis[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }

        }
        return 0;
    }
};