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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<int> res;
        res.push_back(root->val);
        vector<int> leftRes = preorderTraversal(root->left);
        vector<int> rightRes = preorderTraversal(root->right);
        res.insert(res.end(),leftRes.begin(),leftRes.end());
        res.insert(res.end(),rightRes.begin(),rightRes.end());
        return res;
    }
};