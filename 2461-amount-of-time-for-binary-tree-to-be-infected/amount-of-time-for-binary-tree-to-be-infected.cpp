class Solution {
public:
    void buildGraph(TreeNode* root, unordered_map<int, vector<int>> &adj) {
        if (!root) return;
        if (root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            buildGraph(root->left, adj);
        }
        if (root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            buildGraph(root->right, adj);
        }
    }

    int bfs(unordered_map<int, vector<int>> &adj, int start) {
        queue<int> q;
        unordered_map<int, int> vis; // Keeps track of visited nodes
        q.push(start);
        vis[start] = 1;
        int time = -1;

        while (!q.empty()) {
            int size = q.size();
            time++; // Increment time for each level
            
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (!vis[neighbor]) {
                        vis[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
            }
        }
        return time;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        buildGraph(root, adj); // Convert tree to graph
        return bfs(adj, start); // Find max time using BFS
    }
};
