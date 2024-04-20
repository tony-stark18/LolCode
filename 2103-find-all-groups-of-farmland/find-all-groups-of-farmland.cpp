#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    pair<int,int> dfs(vector<vector<int>>& land, int r, int c, int dr[], int dc[], int m, int n){
        if(r<0 || r>=m || c<0 || c>=n || land[r][c]!=1) return {-1, -1};
        land[r][c] = 2; // Mark as visited
        pair<int,int> br = {r, c};
        for(int i=0; i<4; i++){
            pair<int,int> next = dfs(land, r+dr[i], c+dc[i], dr, dc, m, n);
            br.first = max(br.first, next.first);
            br.second = max(br.second, next.second);
        }
        return br;
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> ans;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(land[i][j] == 1){
                    pair<int,int> br = dfs(land, i, j, dr, dc, m, n);
                    ans.push_back({i, j, br.first, br.second});
                }
            }
        }
        return ans;
    }
};
