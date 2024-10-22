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
    void soln(TreeNode* root, vector<long long>& sums, int d) {
        if (root == nullptr) {
            return;
        }
        if (sums.size() > d) {
            sums[d] += root->val;
        }
        else {
            sums.push_back(root->val);
        }
        soln(root->left, sums, d + 1);
        soln(root->right, sums, d + 1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sums;
        soln(root, sums, 0);
        sort(sums.begin(), sums.end(),
             [](long long a, long long b) { return a > b; });
        if(sums.size()<k) return -1;
        return sums[k - 1];
    }
};