class Solution {
public:
    string frequencySort(string s) {
        int freq[128];
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - '0']++;
        }
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 128; i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], i+'0'});
            }
        }
        string ans = "";
        while(!pq.empty()){
            auto t  = pq.top();
            pq.pop();
            int f = t.first;
            char c= t.second;
            while(f){
                ans+=c;
                f--;
            }
        }
        return ans;
    }
};