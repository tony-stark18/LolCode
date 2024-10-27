class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prev_max(n,-1);
        vector<int> next_max(n,-1);
        int max1 = height[0];
        int max2 = height[n-1];
        for(int i=1;i<n-1;i++){
            if(height[i]<max1){
                prev_max[i]=max1;
            } else{
                max1 = height[i];
            }

            if(height[n-i-1]<max2){
                next_max[n-i-1] = max2;
            } else{
                max2 = height[n-i-1];
            }
        }

        int ans = 0;
        for(int i=1;i<n-1;i++){
            if(prev_max[i]==-1 || next_max[i]==-1) continue;
            ans+=min(prev_max[i],next_max[i])-height[i];
        }
        return ans;
        
    }
};