class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int cur;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                cur=nums[i];
                count++;
            }
            else if(nums[i]==cur)
                count++;
            else
                count--;
            
        }
        return cur;
    }
};