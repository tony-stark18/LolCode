class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> ans;
        for(int i=0;i<searchWord.length();i++){
            vector<string> words;
            for(auto product:products){
                bool flag = true;
                for(int j=0;j<=i;j++){
                    if(product[j]!=searchWord[j]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    words.push_back(product);
                    if(words.size()==3) break;
                }
            }
            ans.push_back(words);
        }
        return ans;
    }
};