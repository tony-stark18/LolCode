class Solution {
public:
    int minDeletions(string s) {
        int freq[26] = {0};
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> fr;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] != 0) {
                fr.push_back(freq[i]);
            }
        }

        sort(fr.begin(), fr.end(), greater<int>());

        unordered_set<int> seenFreqs;
        int deletions = 0;
        
        for (int f : fr) {
            while (f > 0 && seenFreqs.find(f) != seenFreqs.end()) {
                f--;
                deletions++;
            }
            if (f > 0) {
                seenFreqs.insert(f);
            }
        }

        return deletions;
    }
};