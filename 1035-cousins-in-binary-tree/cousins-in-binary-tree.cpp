class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {-1, 0}});
        
        int x_parent = -1, y_parent = -1, x_depth = -1, y_depth = -1;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [node, info] = q.front(); q.pop();
                int parent = info.first, depth = info.second;
                
                if (node->val == x) {
                    x_parent = parent;
                    x_depth = depth;
                }
                if (node->val == y) {
                    y_parent = parent;
                    y_depth = depth;
                }
                
                if (node->left) q.push({node->left, {node->val, depth + 1}});
                if (node->right) q.push({node->right, {node->val, depth + 1}});
            }
            
            if (x_parent != -1 && y_parent != -1) break;
        }
        
        return (x_depth == y_depth) && (x_parent != y_parent);
    }
};