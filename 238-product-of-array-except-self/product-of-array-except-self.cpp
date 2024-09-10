class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        int prp = 1;
        int srp = 1;
        for(int i=0;i<n;i++){
            prp*=nums[i];
            prefix[i] = prp;
            srp*=nums[n-i-1];
            suffix[n-i-1] = srp;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            int pre = i>0 ? prefix[i-1]:1;
            int suf = i<n-1 ? suffix[i+1]:1;
            ans.push_back(pre*suf);
        }
        return ans;
    }
};