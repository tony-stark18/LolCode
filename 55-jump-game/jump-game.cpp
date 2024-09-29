class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIcanReach = 0;
        for(int i=0;i<nums.size();i++){
            if(i>maxIcanReach) return false;
            maxIcanReach = max(maxIcanReach,i+nums[i]);
            if(maxIcanReach>=nums.size()) return true;
        }
        return true;
    }
};