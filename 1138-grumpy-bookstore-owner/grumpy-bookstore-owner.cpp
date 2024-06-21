class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (!grumpy[i])
                sum += customers[i];
        }
        int maxSum = sum;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i])
                sum += customers[i];
        }
        maxSum = max(sum,maxSum);
        int left = 1;
        int right = minutes;
        while (right < n) {
            if(grumpy[left-1]) sum-=customers[left-1];
            if(grumpy[right]) sum+=customers[right];
            maxSum = max(sum,maxSum);
            left++;
            right++;
        }
        return maxSum;
    }
};