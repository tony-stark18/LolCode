#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& shorter = (nums1.size() < nums2.size()) ? nums1 : nums2;
        vector<int>& longer = (nums1.size() < nums2.size()) ? nums2 : nums1;

        unordered_map<int, int> digitCount;

        // Record counts for the shorter array
        for (int num : shorter) {
            digitCount[num]++;
        }

        // Iterate over the longer array and check for intersection
        vector<int> result;
        for (int num : longer) {
            if (digitCount.find(num) != digitCount.end() && digitCount[num] > 0) {
                result.push_back(num);
                digitCount[num]--;
            }
        }

        return result;
    }
};
