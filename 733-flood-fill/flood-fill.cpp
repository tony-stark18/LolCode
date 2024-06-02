class Solution {
public:
    void dfs(vector<vector<int>> &ff,vector<vector<int>> image,int r,int c,int color,int dr[],int dc[],int m,int n){
        ff[r][c]=color;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nc>=0 && nr<m && nc<n && image[nr][nc]==image[r][c] && ff[nr][nc]!=color){
                dfs(ff,image,nr,nc,color,dr,dc,m,n);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
        vector<vector<int>> ff = image;
        dfs(ff,image,sr,sc,color,dr,dc,m,n);
        return ff;
    }
};