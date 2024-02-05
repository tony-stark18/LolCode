class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> ff = image;
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        ff[sr][sc] = color;
        vis[sr][sc]=1;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && image[r][c]==image[nr][nc] && !vis[nr][nc]){
                    ff[nr][nc]=color;
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
            // if(r-1>=0 && image[r][c]==image[r-1][c] && !vis[r-1][c]){
            //     ff[r-1][c]=color;
            //     q.push({r-1,c});
            //     vis[r-1][c]=1;
            // }
            // if(r+1<m && image[r][c]==image[r+1][c] && !vis[r+1][c]){
            //     ff[r+1][c]=color;
            //     q.push({r+1,c});
            //     vis[r+1][c]=1;
            // }
            // if(c-1>=0 && image[r][c]==image[r][c-1] && !vis[r][c-1]){
            //     ff[r][c-1]=color;
            //     vis[r][c-1]=1;
            //     q.push({r,c-1});
            // }
            // if(c+1<n && image[r][c]==image[r][c+1] && !vis[r][c+1]){
            //     ff[r][c+1]=color;
            //     vis[r][c+1]=1;
            //     q.push({r,c+1});
            // }

        }
        return ff;
    }
};