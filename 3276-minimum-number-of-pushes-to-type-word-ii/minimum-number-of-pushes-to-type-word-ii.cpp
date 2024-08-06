class Solution {
public:
    int minimumPushes(string word) {
        int freq[26];
        for(char c:word){
            freq[c-'a']++;
        }
        sort(freq,freq+26);
        int chars = 0;
        int press = 0;
        for(int i=25;i>=0;i--){
            if(freq[i]==0) break;
            press = press+((chars/8)+1)*freq[i];
            chars++;
        }
        return press;
    }
};