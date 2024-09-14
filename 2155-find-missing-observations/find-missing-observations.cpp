class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int m = rolls.size();
        int totalSum = mean * (m + n); // Desired total sum for m + n rolls
        int sumRequired = totalSum - sum; // Required sum for the missing n rolls
        
        if (sumRequired < n || sumRequired > 6 * n) {
            return {};
        }
        cout<< sumRequired;
        vector<int> ans(n, 1);
        sumRequired -= n; 
        for (int i = 0; i < n && sumRequired > 0; i++) {
            int add = min(5, sumRequired); 
            ans[i] += add;
            sumRequired -= add;
        }
        return ans;
    }
};
