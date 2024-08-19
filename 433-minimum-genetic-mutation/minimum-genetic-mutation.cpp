class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> words(bank.begin(),bank.end());
        words.erase(startGene);
        queue<pair<string,int>> q;
        vector<char> chars = {'A','C','G','T'};
        q.push({startGene,0});
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word==endGene) return steps;
            for(int i=0;i<8;i++){
                char t = word[i];
                for(char c:chars){
                    word[i] = c;
                    if(words.find(word)!=words.end()){
                        q.push({word,steps+1});
                        words.erase(word);
                    }
                        
                }       
                word[i] = t;
            }
        }
        return -1;
    }
};