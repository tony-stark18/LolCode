class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        int pivot = arr[m*n/2];
        int ans = 0;
        for(int i:arr){
            if(abs(i-pivot)%x) return -1;
            ans+=abs(i-pivot)/x;
        }
        return ans;
    }
};