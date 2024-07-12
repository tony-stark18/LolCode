class Solution {
public:
    int minDeletions(string s) {
        int freq[26];
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        vector<int> fr;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                fr.push_back(freq[i]);
            }
        }
        sort(fr.begin(),fr.end());
        for(int i:fr){
            cout<<i<<" ";
        }
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i=0;i<fr.size();i++){
            while(mp.find(fr[i])!=mp.end()){
                ans++;
                fr[i]--;
            }
            if(fr[i]!=0) mp.insert({fr[i],0});
        }
        return ans;
    }
};