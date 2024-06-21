class Solution {
public:
    bool soln(vector<vector<int>>& grid,int r,int c,int n,vector<vector<int>> dir){
        if(grid[r][c]==n*n-1) return true;
        bool flag = false;
        for(int i=0;i<8;i++){
            int nr = r+dir[i][0];
            int nc = c+dir[i][1];
            int prev = grid[r][c];
            if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==prev+1){
                if(soln(grid,nr,nc,n,dir)){
                    flag = true;
                }
            }
        }
        return flag ;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return false;
        vector<vector<int>> dir = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
        return soln(grid,0,0,grid.size(),dir);
    }
};