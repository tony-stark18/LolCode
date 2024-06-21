class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int totalSatisfied = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!grumpy[i]) {
                totalSatisfied += customers[i];
            }
        }
        
        int extraSatisfied = 0;
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i]) {
                extraSatisfied += customers[i];
            }
        }
        
        int maxExtraSatisfied = extraSatisfied;
        
        for (int i = minutes; i < n; ++i) {
            if (grumpy[i]) {
                extraSatisfied += customers[i];
            }
            if (grumpy[i - minutes]) {
                extraSatisfied -= customers[i - minutes];
            }
            maxExtraSatisfied = max(maxExtraSatisfied, extraSatisfied);
        }
        
        return totalSatisfied + maxExtraSatisfied;
    }
};
