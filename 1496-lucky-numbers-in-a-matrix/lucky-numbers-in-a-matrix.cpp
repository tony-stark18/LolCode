class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++){
            int min = mat[i][0];
            int ind = 0;
            for(int j=0;j<n;j++){
                if(min>mat[i][j]){
                    min = mat[i][j];
                    ind = j;
                }
            }
            int max = mat[0][ind];
            for(int k=0;k<m;k++){
                if(max<mat[k][ind]){
                    max = mat[k][ind];
                }
            }
            if(min==max) ans.push_back(min);
        }
        return ans;
    }
};