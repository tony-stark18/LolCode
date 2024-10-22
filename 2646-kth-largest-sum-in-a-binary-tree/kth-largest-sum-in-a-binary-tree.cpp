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
    int get_depth(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int ld = get_depth(root->left);            
        int rd = get_depth(root->right);  
        return max(ld,rd)+1;
    }
    void soln(TreeNode* root,vector<long long> &sums,int d){
        if(root==nullptr){
            return;
        }
        sums[d]+=root->val;
        soln(root->left,sums,d+1);
        soln(root->right,sums,d+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        int depth = get_depth(root);
        if(k>depth) return -1;
        vector<long long> sums(depth);
        soln(root,sums,0);
        sort(sums.begin(),sums.end(),[](long long a,long long b){
            return a>b;
        });
        return sums[k-1];
    }
};