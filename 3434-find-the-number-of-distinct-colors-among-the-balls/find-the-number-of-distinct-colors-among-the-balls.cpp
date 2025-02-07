class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> balls;  // Maps index to color
        unordered_map<int, int> colors; // Maps color to count
        vector<int> ans;
        
        for (const auto &q : queries) {
            int index = q[0], color = q[1];
            
            if (balls.count(index)) { // If the index already has a ball
                int prevColor = balls[index];
                if (--colors[prevColor] == 0) { // Decrement color count and remove if zero
                    colors.erase(prevColor);
                }
            }
            
            balls[index] = color; // Assign new color
            colors[color]++; // Increment new color count
            
            ans.push_back(min((int)colors.size(), (int)balls.size()));
        }
        
        return ans;
    }
};
