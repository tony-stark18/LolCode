int IO = []{
    ios::sync_with_stdio(false); cin.tie(nullptr); return 0;
}();
class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int jumps = 0;
        while(r<nums.size()-1){
            int farthest = 0;
            jumps++;
            for(int i = l;i<=r;i++){
                farthest = max(farthest,i+nums[i]);
            }
            l = r+1;
            r = farthest;
        }
        return jumps;
    }
};