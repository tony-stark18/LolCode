class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remFreq(k, 0);
        
        for(int i : arr) {
            int rem = ((i % k) + k) % k; 
            remFreq[rem]++;
        }

        for(int i = 1; i <= k/2; i++) {
            if(remFreq[i] != remFreq[k - i]) {
                return false;
            }
        }

        if(remFreq[0] % 2 != 0) {
            return false;
        }

        return true;
    }
};
