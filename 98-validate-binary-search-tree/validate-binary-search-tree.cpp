/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
struct ReturnType {
    bool res;
    long max_val;
    long min_val;
};
ReturnType soln(TreeNode* root) {
    if (!root) {
        return {true, LONG_MIN, LONG_MAX};
    }
    ReturnType l = soln(root->left);
    ReturnType r = soln(root->right);
    bool ans = l.res && r.res && root->val > l.max_val && root->val < r.min_val;
    return {ans, max((long)root->val, r.max_val),
            min((long)root->val, l.min_val)};
}
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        ReturnType ans = soln(root);
        return ans.res;
    }
};