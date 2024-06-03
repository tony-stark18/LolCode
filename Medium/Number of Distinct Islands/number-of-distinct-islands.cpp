//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(vector<vector<int>> &vis,vector<vector<int>>& grid,int r,int c,int m,int n,vector<pair<int,int>> &vec,int dr[],int dc[],int r0,int c0){
        vis[r][c]=1;
        vec.push_back({r-r0,c-c0});
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(vis,grid,nr,nc,m,n,vec,dr,dc,r0,c0);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        set<vector<pair<int,int>>> st;
        int dr[] ={-1,1,0,0};
        int dc[] = {0,0,-1,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> vec;
                    dfs(vis,grid,i,j,m,n,vec,dr,dc,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();   
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends