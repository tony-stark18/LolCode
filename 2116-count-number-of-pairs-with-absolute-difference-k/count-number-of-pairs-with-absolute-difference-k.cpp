class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++){
            if(map.find(nums[i]-k)!=map.end()){
                count+=map[nums[i]-k];
            }
            if(map.find(nums[i]+k)!=map.end()){
                count+=map[nums[i]+k];
            }
            map[nums[i]]++;
        }
        return count;
    }
};