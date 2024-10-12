class Solution {
public:
    long long helper(vector<int>& piles,int k){
        long long res = 0;
        for(int i:piles){
            if(i%k==0) res+=i/k;
            else res+=(i/k)+1;
        }
        return res;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        while(l<=r){
            int mid = l + (r - l) / 2;
            if(helper(piles,mid)<=h){
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};