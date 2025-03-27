class Solution {
public:
    int getMajority(vector<int> &nums){
        int n = nums.size();
        int count = 0;
        int me = -1;
        for(int i=0;i<n;i++){
            if(count==0){
                count=1;
                me = nums[i];
            } else{
                if(nums[i]==me) count++;
                else count--;
            }
        }
        return me;
    }
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        int me = getMajority(nums);
        int count = 0,count2 = 0;
        for(int i=0;i<n;i++) count+=nums[i]==me;
        for(int i=0;i<n-1;i++){
            count2+=nums[i]==me;
            if(count2*2>i+1 && (count-count2)*2>n-i-1) return i;
        }
        return -1;
    }
};