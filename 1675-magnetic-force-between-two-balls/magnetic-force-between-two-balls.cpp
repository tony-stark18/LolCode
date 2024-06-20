class Solution {
public:
    int helper(vector<int>& position,int gap,int n){
        int pos = position[0];
        int ballCount=1;
        for(int i=1;i<n;i++){
            if(position[i]-pos>=gap){
                ballCount++;
                pos = position[i];
            }
        }
        return ballCount;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int low = 1;
        int high = position[n-1];
        while(low<=high){
            int mid = low+(high-low)/2;
            int ball = helper(position,mid,n);
            if(ball<m) high = mid-1;
            else low = mid+1;
        }
        return high;
    }
};