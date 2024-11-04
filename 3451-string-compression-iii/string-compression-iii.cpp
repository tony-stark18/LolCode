class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int count = 1;
        for(int i=1;i<word.length();i++){
            if(word[i]==word[i-1]){
                count++;
            }
            else{
                ans+=('0'+count);
                ans+=word[i-1];
                count=1;
            }
            if(count>9){
                ans+=('0'+9);
                ans+=word[i-1];
                count=1;
            }
        }
        ans+=('0'+count);
        ans+=word[word.length()-1];
        cout<<ans;
        return ans;
    }
};