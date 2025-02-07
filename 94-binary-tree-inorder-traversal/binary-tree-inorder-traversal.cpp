/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<int> res;
        vector<int> leftRes = inorderTraversal(root->left);
        res.insert(res.end(),leftRes.begin(),leftRes.end());
        res.push_back(root->val);
        vector<int> rightRes = inorderTraversal(root->right);
        res.insert(res.end(),rightRes.begin(),rightRes.end());
        return res;
    }
};