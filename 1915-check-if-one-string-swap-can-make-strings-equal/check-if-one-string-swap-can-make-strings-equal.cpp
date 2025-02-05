class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int count = 0;
        int ind1 = -1;
        int ind2 = -1;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                if(ind1==-1){
                    ind1 = i;
                } else{
                    ind2 = i;
                }
            }
            count+=s1[i]!=s2[i];
        }
        if(count!=2) return false;
        swap(s1[ind1],s1[ind2]);
        return s1==s2;
    }
};