class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int z = 0;
        int o = 0;
        int t = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) z++;
            else if(nums[i]==1) o++;
            else t++;
        }
        int k = 0;
        for(int i=0;i<z;i++){
            nums[k]=0;
            k++;
        }
        for(int i=0;i<o;i++){
            nums[k]=1;
            k++;
        }
        for(int i=0;i<t;i++){
            nums[k]=2;
            k++;
        }
    }
};