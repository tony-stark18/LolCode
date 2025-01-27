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
    void calc(TreeNode* root,vector<long long> &lSum,int depth){
        if(root==nullptr){
            return;
        }
        if(lSum.size()<depth){
            lSum.push_back(root->val);
        } else{
            lSum[depth-1]+=(long long)root->val;
        }
        calc(root->left,lSum,depth+1);
        calc(root->right,lSum,depth+1);
    }
    int maxLevelSum(TreeNode* root) {
        vector<long long> lSum;
        calc(root,lSum,1);
        int ans = -1;
        long long maxSum = LLONG_MIN; 
        for(int i=0;i<lSum.size();i++){
            if(maxSum<lSum[i]){
                ans=i+1;
                maxSum = lSum[i];
            }
        }
        return ans;
    }
};