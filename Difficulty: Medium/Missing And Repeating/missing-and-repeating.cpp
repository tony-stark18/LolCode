//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        unordered_map<int, int> map;
        int d = -1, m = -1;
    
        for (int num : arr) {
            map[num]++;
        }
    
        for (int i = 1; i <= n; ++i) {
            if (map[i] == 2) {
                d = i;
            } else if (map[i] == 0) {
                m = i;
            }
            if (d != -1 && m != -1) {
                break;
            }
        }
    
        return {d, m};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends