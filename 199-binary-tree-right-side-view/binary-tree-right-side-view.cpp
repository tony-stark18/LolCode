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
    void soln(TreeNode* root,vector<int> &ans, int &maxD,int currD){
        if(root==nullptr) return;
        if(currD>maxD){
            ans.push_back(root->val);
            maxD = currD;
        }
        soln(root->right,ans,maxD,currD+1);
        soln(root->left,ans,maxD,currD+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int maxD = 0;
        soln(root,ans,maxD,1);
        return ans;
    }
};