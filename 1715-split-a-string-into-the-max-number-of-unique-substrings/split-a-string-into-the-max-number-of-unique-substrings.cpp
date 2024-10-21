class Solution {
public:
    int soln(const string &s,unordered_set<string> &set,int i){
        if(i==s.length()){
            return 0;
        }
        // string str = "";
        // str+=s[i];
        // if(set.find(str)==set.end()){
        //     set.insert(str);
        //     return 1+soln(s,set,i+1);
        // }
        int max_res = 0;
        for(int ind = i;ind<s.length();ind++){
            string str = s.substr(i,ind-i+1);
            if(set.find(str)==set.end()){
                set.insert(str);
                int res = 1+soln(s,set,ind+1);
                max_res = max(max_res,res);
                set.erase(str);
            }
        }
        return max_res;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        return soln(s,set,0);
    }
};