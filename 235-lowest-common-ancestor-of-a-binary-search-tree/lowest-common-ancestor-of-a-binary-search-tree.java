/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public boolean soln(TreeNode root,TreeNode p,TreeNode q,TreeNode[] ans){
        if(root==null) return false;
        boolean self = root.val==p.val || root.val==q.val;
        boolean left = soln(root.left,p,q,ans);
        boolean right = soln(root.right,p,q,ans);

        if((self && left) || (self && right) || (left && right)){
            ans[0]=root;
        }
        return self || left || right;
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode ans[] = {null};
        soln(root,p,q,ans);
        return ans[0];
    }
}