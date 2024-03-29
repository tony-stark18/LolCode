class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> ff = image;
        // vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        ff[sr][sc] = color;
        // vis[sr][sc]=1;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && image[r][c]==image[nr][nc] && ff[nr][nc]!=color){
                    ff[nr][nc]=color;
                    q.push({nr,nc});
                    // vis[nr][nc]=1;
                }
            }

        }
        return ff;
    }
};