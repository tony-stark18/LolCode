class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxR = 0;
        for(int i=0;i<nums.size();i++){
            if(i>maxR) return false;
            maxR = max(maxR,i+nums[i]);
        }
        return true;
    }
};