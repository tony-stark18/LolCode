class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        // int i=0;
        while(columnNumber>26){
            char c;
            if(columnNumber%26==0){
                c = 'Z';
                columnNumber=columnNumber/26-1;
            }
            else{
                c = columnNumber%26 + 64;
                columnNumber/=26;
            }
            s+= c;
        }
        char c = 64+columnNumber;
        s+=c;
        reverse(s.begin(),s.end());
        return s;
    }
};