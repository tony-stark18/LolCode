class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        if (k <= n / 2) {
            priority_queue<int, vector<int>, greater<int>> minHeap;
            for (int num : nums) {
                minHeap.push(num);
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
            return minHeap.top();
        } else {
            // Use max heap of size (n - k + 1) to find (n-k+1)th smallest
            // element
            int newK = n - k + 1;
            priority_queue<int> maxHeap;
            for (int num : nums) {
                maxHeap.push(num);
                if (maxHeap.size() > newK) {
                    maxHeap.pop();
                }
            }
            return maxHeap.top();
        }
    }
};