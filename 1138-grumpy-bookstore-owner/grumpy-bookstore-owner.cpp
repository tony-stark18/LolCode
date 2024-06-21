class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int totalSatisfied = 0;
        
        // Calculate the initially satisfied customers (when grumpy[i] is 0)
        for (int i = 0; i < n; ++i) {
            if (!grumpy[i]) {
                totalSatisfied += customers[i];
            }
        }
        
        // Calculate the initial extra satisfied customers in the first 'minutes' window
        int extraSatisfied = 0;
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i]) {
                extraSatisfied += customers[i];
            }
        }
        
        int maxExtraSatisfied = extraSatisfied;
        
        // Slide the window across the array
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
