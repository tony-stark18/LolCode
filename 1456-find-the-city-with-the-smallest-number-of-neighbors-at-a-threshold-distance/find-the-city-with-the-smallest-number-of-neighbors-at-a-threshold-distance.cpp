class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    matrix[i][j]=0;
                }
            }
        }
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            matrix[u][v]=w;
            matrix[v][u]=w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        int ans = 0;
        int min_cities = INT_MAX;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=min_cities){
                min_cities=count;
                ans = i;
            }

        }
        return ans;
    }
};