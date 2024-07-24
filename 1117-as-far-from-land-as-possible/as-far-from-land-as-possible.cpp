class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        set<pair<int,int>> land;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) land.insert({i,j});
            }
        }
        if(land.size()==0 || land.size()==m*n) return -1;
        int ans = INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int dist = INT_MAX;
                    for(auto it:land){
                        dist = min(dist,abs(it.first-i)+abs(it.second-j));
                    }
                    ans = max(ans,dist);
                }
            }
        }
        return ans;

    }
};