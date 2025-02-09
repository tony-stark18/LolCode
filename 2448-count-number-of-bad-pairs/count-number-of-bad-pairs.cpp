class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long total_pairs = n*(n-1)/2;
        long long good_pairs = 0;
        unordered_map<long long,long long> map;
        for(long long i=0;i<n;i++){
            int t = nums[i]-i;
            good_pairs += map[t];
            map[t]++;
        }
        return total_pairs-good_pairs;
    }
};