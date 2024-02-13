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
    public boolean check(TreeNode root, int targetSum){
        if(root==null) return false;
        if (root.left == null && root.right == null && targetSum - root.val == 0) {
            return true;
        }
        boolean lr = check(root.left,targetSum-root.val);
        boolean rr = check(root.right,targetSum-root.val);
        return lr || rr;
    }
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root==null) return false;
        return check(root,targetSum);
    }   
}