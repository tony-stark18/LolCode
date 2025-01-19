int IO = []{
    ios::sync_with_stdio(false); cin.tie(nullptr); return 0;
}();
class Solution {
public:
    int min_safe_factor(vector<pair<int,int>> thieves,int r,int c){
        int safe_factor = INT_MAX;
        for(auto it:thieves){
            safe_factor = min(safe_factor,abs(it.first-r)+abs(it.second-c));
        }
        return safe_factor;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return 0;
        vector<pair<int,int>> thieves;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    thieves.push_back({i,j});
                }
            }
        }
        priority_queue<pair<int,pair<int,int>>> pq; 
        int safe_factor = min_safe_factor(thieves,0,0);
        // cout<<safe_factor;
        pq.push({safe_factor,{0,0}});
        vector<vector<int>> factors(n,vector<int>(n,0));
        factors[0][0]=safe_factor;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int factor = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r==n-1 && c==n-1) return factor;
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<n){
                    safe_factor = min_safe_factor(thieves,nr,nc);
                    if(min(safe_factor,factor)>factors[nr][nc]){
                        pq.push({min(safe_factor,factor),{nr,nc}});
                        factors[nr][nc] = min(safe_factor,factor);
                    }
                }
            }
        }
        return 0;
    }
};