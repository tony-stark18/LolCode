class Solution {
public:
    void csort(vector<int>& arr) {
        if (arr.empty())
            return;
        int maxElement = *max_element(arr.begin(), arr.end());
        vector<int> count(maxElement + 1, 0);
        for (int num : arr) {
            count[num]++;
        }
        for (int i = 1; i <= maxElement; i++) {
            count[i] += count[i - 1];
        }
        vector<int> output(arr.size());
        for (int i = arr.size() - 1; i >= 0; i--) {
            output[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }
        arr = output;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> vect;
        for (int i = 0; i < n; i++) {
            vect.push_back({difficulty[i], profit[i]});
        }
        sort(vect.begin(), vect.end());
        csort(worker);
        int ans = 0;
        int ind = 0;
        int maxPr = 0;

        for (int i : worker) {
            while (ind < n && vect[ind].first <= i) {
                maxPr = max(maxPr, vect[ind].second);
                ind++;
            }
            ans += maxPr;
        }
        return ans;
    }
};
