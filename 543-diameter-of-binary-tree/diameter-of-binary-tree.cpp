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
int soln(TreeNode* root,int &ans){
    if(!root) return 0;
    int lh = soln(root->left,ans);
    int rh = soln(root->right,ans);
    ans = max(ans,lh+rh+1);
    return max(lh,rh)+1;
}
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        soln(root,ans);
        return ans-1;
    }
};