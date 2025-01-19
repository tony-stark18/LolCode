class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n = grid.size();
        queue<pair<int,pair<int,int>>> pq;
        pq.push({1,{0,0}});
        vector<vector<int>> distance(n,vector<int>(n,1e9));
        distance[0][0] = 1;
        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            int dist = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r==n-1 && c==n-1) return dist;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr = r+i;
                    int nc = c+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<n && !grid[nr][nc] && distance[nr][nc]>dist+1){
                        pq.push({dist+1,{nr,nc}});
                        distance[nr][nc]=dist+1;
                    }
                }
            }
        }
        return -1;
    }
};