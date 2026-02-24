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
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        TreeNode* curr = root;
        TreeNode* parent = nullptr;
        while (curr && curr->val != key) {
            parent = curr;
            if (key > curr->val)
                curr = curr->right;
            else
                curr = curr->left;
        }
        if (!curr)
            return root;
        if (curr->left && curr->right) {
            TreeNode* successor_parent = curr;
            TreeNode* successor = curr->right;
            while (successor->left) {
                successor_parent = successor;
                successor = successor->left;
            }
            curr->val = successor->val;
            curr = successor;
            parent = successor_parent;
        }
        TreeNode* child = curr->left ? curr->left : curr->right;
        if (!parent) {
            delete curr;
            return child;
        }
        if (parent->left == curr) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        delete curr;
        return root;
    }
};