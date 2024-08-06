class Solution {
public:
    int minimumPushes(string word) {
        int freq[26] = {0};
        
        // Count the frequency of each character
        for(char c : word) {
            freq[c - 'a']++;
        }
        
        // Sort frequencies in ascending order
        sort(freq, freq + 26);
        
        int chars = 0;
        int press = 0;
        
        // Calculate minimum presses needed
        for(int i = 25; i >= 0; i--) {
            if(freq[i] == 0) break;
            press += ((chars / 8) + 1) * freq[i];
            chars++;
        }
        
        return press;
    }
};
