class Solution {
public:
    int addMinimum(string word) {
        int req = 0;
        int len = 1;
        for(int i=word.length()-2;i>=0;i--){
            if(word[i]<word[i+1]) len++;
            else{
                req+=(3-len);
                len = 1;
            }
        }
        return req+(3-len);
    }
};