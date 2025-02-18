class Solution {
public:
    int visited[10];
    bool flag = true;
    vector<string> res;
    void soln(int ind,int num,string pattern,string ans){
        if(ind==pattern.length()){
            flag= false;
            res.push_back(ans);
            return;
        }
        char c = pattern[ind];
        if(c=='I'){
            for(int i=1;i<=9;i++){
                if(!visited[i] && flag && i>num){
                    visited[i]=1;
                    char t = '0'+i;
                    soln(ind+1,i,pattern,ans+t);
                    visited[i]=0;
                }
            }
        }
        else{
            for(int i=1;i<=9;i++){
                if(!visited[i] && flag && i<num){
                    visited[i]=1;
                    char t = '0'+i;
                    soln(ind+1,i,pattern,ans+t);
                    visited[i]=0;
                }
            }
        }
    }
    string smallestNumber(string pattern) {
        int n= pattern.length();
        for(int i=1;i<=9;i++){
            char c = '0'+i;
            string s = "";
            s+=c;
            visited[i]=1;
            soln(0,i,pattern,s);
            visited[i]=0;
        }
        sort(res.begin(),res.end());
        cout<<res[0];
        return res[0];
    }
};