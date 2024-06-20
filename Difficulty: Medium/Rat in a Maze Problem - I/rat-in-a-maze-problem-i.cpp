//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfs(vector<vector<int>> &m,vector<vector<int>> &vis, int n,vector<string> &ans,string s,int r,int c,int dr[],int dc[]){
        if(r==n-1 && c==n-1){
            ans.push_back(s);
            return;
        }
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            char c;
            if(i==0) c='L';
            else if(i==1) c='R';
            else if(i==2) c='U';
            else if(i==3) c='D';
            if(nr>=0 && nr<n && nc>=0 && nc<n && m[nr][nc] && !vis[nr][nc]){
                dfs(m,vis,n,ans,s+c,nr,nc,dr,dc);
            }
        }
        vis[r][c]=0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==0) return ans;
        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};
        vector<vector<int>> vis(n,vector<int>(n,0));
        dfs(m,vis,n,ans,"",0,0,dr,dc);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends