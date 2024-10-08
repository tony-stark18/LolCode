class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;
        int l = 0;
        int r = s.length()-1;
        int count = 0;
        while(l<r){
            char c = s[l];
            if(c=='[') balance++;
            else balance--;
            if(balance<0){
                while(r>l){
                    if(s[r]=='['){
                        swap(s[l],s[r]);
                        balance+=2;
                        count++;
                        break;
                    }
                    r--;
                }
            }
            l++;
        }
        cout<<s;
        return count;

    }
};