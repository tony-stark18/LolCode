class Solution {
public:
    bool check(vector<int>& nums) {
        int breakP = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                breakP++;
            }
        }
        if(breakP>1) return false;
        if(breakP==0) return true;
        return nums[0]>=nums[nums.size()-1];
    }
};