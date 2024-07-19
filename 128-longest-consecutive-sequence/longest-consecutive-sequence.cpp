class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int i:nums) set.insert(i);
        int ans = 0;
        for(auto i:set){
            if(set.find(i-1)==set.end()){
                int count = 0;
                int x = i;
                while(set.find(x++)!=set.end()){
                    count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};