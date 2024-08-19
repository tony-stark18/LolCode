class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n <= 3)
            return true;

        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }

        return true;
    }
    int minSteps(int n) {

        vector<int> ans(n + 1);
        ans[1] = 0;
        for (int i = 2; i <= n; i++) {
            if (isPrime(n))
                ans[i] = i;
            int count = i;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    int t = i/j;
                    count = min(count,ans[j]+t);
                }
            }
            ans[i]=count;
        }
        for(auto it:ans) cout<<it<<" ";
        return ans[n];
    }
};