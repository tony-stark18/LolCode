class Solution {
public:
    int helper(vector<int>& bloomDay,int day,int k){
        int bqt = 0;
        int flower = 0;
        for(int i:bloomDay){
            if(i<=day) flower++;
            else {
                bqt+=flower/k;
                flower=0;
            }
        }
        bqt+=flower/k;
        return bqt;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *(min_element(bloomDay.begin(), bloomDay.end()));
        int high = *(max_element(bloomDay.begin(), bloomDay.end()));
        if(helper(bloomDay,high,k)<m) return -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int bqt = helper(bloomDay,mid,k);
            if(bqt>=m) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};