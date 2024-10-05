class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        vector<int> s1arr(26, 0), s2arr(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            s1arr[s1[i] - 'a']++;
            s2arr[s2[i] - 'a']++;
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (s1arr[i] == s2arr[i])
                count++;
        }

        for (int i = 0; i < s2.length() - s1.length(); i++) {
            if (count == 26)
                return true;

            int r = s2[i + s1.length()] - 'a', l = s2[i] - 'a';
            
            s2arr[r]++;
            if (s2arr[r] == s1arr[r]) {
                count++;
            } else if (s2arr[r] == s1arr[r] + 1) {
                count--;
            }
            
            s2arr[l]--;
            if (s2arr[l] == s1arr[l]) {
                count++;
            } else if (s2arr[l] == s1arr[l] - 1) {
                count--;
            }
        }

        return count == 26;
    }
};