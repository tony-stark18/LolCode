class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int ind1 = -1;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                if(ind1==-1){
                    ind1 = i;
                } else{
                    swap(s1[i],s1[ind1]);
                    return s1==s2;
                }
            }
        }
        return s1==s2;
    }
};