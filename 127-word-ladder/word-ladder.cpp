class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> words;
        for (const auto& it : wordList) {
            words.insert(it);
        }
        words.erase(beginWord);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()) {
            string word = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (word == endWord)
                return dist;
            for (int i = 0; i < word.size(); i++) {
                char t = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (words.find(word) != words.end()) {
                        words.erase(word);
                        q.push({word, dist + 1});
                    }
                }
                word[i] = t;
            }
        }
        return 0;
    }
};