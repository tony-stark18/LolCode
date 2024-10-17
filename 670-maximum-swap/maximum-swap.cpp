class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        vector<int> temp(n,-1);
        for(int i=0;i<n;i++){
            char maxI = i;
            for(int j=i+1;j<n;j++){
                if(s[j]>=s[maxI] && s[i]!=s[j]){
                    maxI = j;
                }   
            }
            temp[i] = maxI;
        }
        for(int i=0;i<n;i++){
            if(temp[i]!=i){
                swap(s[i],s[temp[i]]);
                return stoi(s);
            }
        }
        return stoi(s);
    }
};