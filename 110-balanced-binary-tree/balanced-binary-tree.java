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
    public int check(TreeNode root){
        if(root==null) return 0;
        int leftH = check(root.left);
        int rightH = check(root.right);
        if(leftH==-1 || rightH==-1) return -1;
        if(Math.abs(leftH-rightH)>1) return -1;
        return Math.max(leftH,rightH)+1;
    }
    public boolean isBalanced(TreeNode root) {
        if(check(root)==-1) return false;
        return true;
    }
}