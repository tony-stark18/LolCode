class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());
        int ans = 0;
        for(int i:nums){
            long long curr = i;
            int count = 0;
            while(set.find((int)curr)!=set.end()){
                count++;
                curr*=curr;
                if(curr>INT_MAX) break;
            }
            ans = max(count,ans);
        }
        if(ans>1) return ans;
        return -1;
    }
};