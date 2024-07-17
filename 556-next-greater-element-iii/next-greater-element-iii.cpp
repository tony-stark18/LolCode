class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digs;
        while (n > 0) {
            digs.push_back(n % 10);
            n /= 10;
        }
        reverse(digs.begin(), digs.end());

        int i = digs.size() - 2;
        while (i >= 0 && digs[i] >= digs[i + 1]) {
            i--;
        }

        if (i < 0) return -1;

        int j = digs.size() - 1;
        while (digs[j] <= digs[i]) {
            j--;
        }
        swap(digs[i], digs[j]);

        reverse(digs.begin() + i + 1, digs.end());

        long long ans = 0;
        for (int d : digs) {
            ans = ans * 10 + d;
        }

        return (ans > INT_MAX) ? -1 : ans;
    }
};
