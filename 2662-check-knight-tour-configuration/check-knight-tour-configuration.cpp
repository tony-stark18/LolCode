class Solution {
public:
    bool IsValid(int row, int col, int n){
        if(row>=0 && row<n && col>=0 && col<n)return true;
        return false;
    }
    bool solve(vector<vector<int>>& grid, vector<vector<int>>& vis,
    vector<vector<int>>& res, int n, int step, int row, int col){
        if(step==(n*n))return true;
        if(IsValid(row, col, n) && !vis[row][col]){
            vis[row][col] = 1;
            res[row][col] = step;
            // int dir[] = {-2, -1, 1, 2};
            if(solve(grid, vis, res, n, step+1, row-1, col+2))return true;
            if(solve(grid, vis, res, n, step+1, row+1, col+2))return true;
            if(solve(grid, vis, res, n, step+1, row-2, col+1))return true;
            if(solve(grid, vis, res, n, step+1, row+2, col+1))return true;
            if(solve(grid, vis, res, n, step+1, row-2, col-1))return true;
            if(solve(grid, vis, res, n, step+1, row+2, col-1))return true;
            if(solve(grid, vis, res, n, step+1, row-1, col-2))return true;
            if(solve(grid, vis, res, n, step+1, row+1, col-2))return true;
            vis[row][col] = 0;
            res[row][col] = -1;
        }
        return false;
    }
    bool check(vector<vector<int>>& grid, int r, int c, int n, int step){
        if(!IsValid(r, c, n))return false;
        return grid[r][c]==step ? true : false;
    }
    bool dfs(int r, int c, int n, vector<vector<int>>& grid, 
    vector<int>& row, vector<int>& col, int step){
        if(step==(n*n)-1)return true;
        for(int i=0;i<8;i++){
            if(check(grid, r+row[i], c+col[i], n, step+1)){
                return dfs(r+row[i], c+col[i], n, grid, row, col, step+1);
            }
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>row = {-2, -2, -1, -1, 1, 1, 2, 2};
        vector<int>col = {-1, 1, -2, 2, -2, 2, -1, 1};
        if(grid[0][0]!=0)return false;
        // for(int i=0;i<n;i++){
            // for(int j=0;i<n;i++){
                // if(grid[i][j]==0)
                return dfs(0, 0, n, grid, row, col, 0);
            // }
        // }
        // vector<vector<int>> vis(n, vector<int>(n, 0));
        // vector<vector<int>> res(n, vector<int>(n, -1));
        // return solve(grid, vis, res, n, 0, 0, 0);
        return false;
    }
};