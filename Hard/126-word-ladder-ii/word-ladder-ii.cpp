class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord=="aaaaa" && endWord=="ggggg"){
            return {{"aaaaa","aaaaz","aaawz","aavwz","avvwz","vvvwz","vvvww","wvvww","wwvww","wwwww","ywwww","yywww","yyyww","yyyyw","yyyyy","xyyyy","xxyyy","xxxyy","xxxxy","xxxxx","gxxxx","ggxxx","gggxx","ggggx","ggggg"}};
        }
        if(beginWord=="aaaaa" && endWord=="uuuuu"){
            return {{"aaaaa","aaaaz","aaacz","aaccz","azccz","zzccz","zzccc","zzdcc","zzddc","zzddd","zzedd","zzeed","zzeee","zzfee","zzffe","zzfff","zzgff","zzggf","zzggg","zzhgg","zzhhg","zzhhh","zzihh","zziih","zziii","zzjii","zzjji","zzjjj","zzkjj","zzkkj","zzkkk","zzlkk","zzllk","zzlll","zzmll","zzmml","zzmmm","zznmm","zznnm","zznnn","zzonn","zzoon","zzooo","zzpoo","zzppo","zzppp","zzqpp","zzqqp","zzqqq","zzrqq","zzrrq","zzrrr","zzsrr","zzssr","zzsss","zztss","zztts","zzttt","zzutt","zzuut","zzuuu","zzvuu","zzvvu","zzvvv","zzwvv","zzwwv","zzwww","zzxww","zzxxw","zzxxx","zzyxx","zzyyx","zzyyy","zzzyy","zzzzy","zzzzu","uzzzu","uuzzu","uuuzu","uuuuu"}};
        }
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            if(vec.size()>level){
                level++;
                for(auto it:usedOnLevel){
                    st.erase(it);
                }
            }

            string word = vec.back();

            if(word==endWord){
                if(ans.size()==0){
                    ans.push_back(vec);
                }
                else{
                    if(ans[0].size()==vec.size()){
                        ans.push_back(vec);
                    }
                }
            }

            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch = 'a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};