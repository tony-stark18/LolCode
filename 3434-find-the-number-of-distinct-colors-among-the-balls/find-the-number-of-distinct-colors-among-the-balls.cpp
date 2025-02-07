class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> balls; 
        unordered_map<int, int> colors;
        vector<int> ans;
        
        for (const auto &q : queries) {
            int index = q[0], color = q[1];
            
            if (balls.count(index)) {
                int prevColor = balls[index];
                if (--colors[prevColor] == 0) {
                    colors.erase(prevColor);
                }
            }
            
            balls[index] = color;
            colors[color]++;
            
            ans.push_back(min((int)colors.size(), (int)balls.size()));
        }
        
        return ans;
    }
};
