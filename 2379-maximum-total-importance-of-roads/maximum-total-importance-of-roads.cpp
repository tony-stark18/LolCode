class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n, 0);
        
        // Count the degree of each node
        for (const auto& road : roads) {
            degrees[road[0]]++;
            degrees[road[1]]++;
        }
        
        // Create a vector of pairs (degree, node) and sort it by degree in descending order
        vector<pair<int, int>> degree_node;
        for (int i = 0; i < n; ++i) {
            degree_node.push_back({degrees[i], i});
        }
        sort(degree_node.rbegin(), degree_node.rend());
        
        // Assign importance values to nodes based on their degree
        vector<int> importance(n, 0);
        for (int i = 0; i < n; ++i) {
            importance[degree_node[i].second] = n - i;
        }
        long long ans = 0;
        for (const auto& road : roads) {
            ans += importance[road[0]] + importance[road[1]];
        }
        
        return ans;
    }
};
