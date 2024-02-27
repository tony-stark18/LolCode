class Solution {
 public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        if(grid[0][0]==1) return -1;
        vector<vector<int>> dis(m,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dis[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int distance = pq.top().first;
            pq.pop();

            for(int i=-1; i<=1; i++) {
                for(int j=-1; j<=1; j++) {
                    if (i == 0 && j == 0) {
                        continue;  // Skip the center point
                    }
                    int nr = row + i;
                    int nc = col + j;

                    if(nr >= 0 && nr < m && nc >= 0 && nc < m && grid[nr][nc] == 0 && distance + 1 < dis[nr][nc]){
                        dis[nr][nc] = distance + 1;
                        pq.push({dis[nr][nc],{nr, nc}});
                    }
                }
            }

        }
        if(dis[m-1][m-1]==1e9) return -1;
        return dis[m-1][m-1]+1;
    }

};