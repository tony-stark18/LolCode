/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int soln(TreeNode root,int depth){
        if(root==null) return Integer.MAX_VALUE;
        if(root.left==null && root.right==null){
            return depth;
        }
        int lr = soln(root.left,depth+1);
        int rr = soln(root.right,depth+1);
        return Math.min(lr,rr);
    }
    public int minDepth(TreeNode root) {
        if(root==null) return 0;
        return soln(root,1);
    }
}