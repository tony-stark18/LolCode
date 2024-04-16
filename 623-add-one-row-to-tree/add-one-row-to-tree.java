/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public void soln(TreeNode root, int val, int depth, int gdepth) {
        if (root == null)
            return;
        if (depth == gdepth - 1) {
            TreeNode lst = root.left;
            TreeNode rst = root.right;
            root.left = new TreeNode(val);
            root.right = new TreeNode(val);
            root.left.left = lst;
            root.right.right = rst;
        }
        soln(root.left, val, depth + 1, gdepth);
        soln(root.right, val, depth + 1, gdepth);
    }

    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(depth==1){
            TreeNode newNode = new TreeNode(val);
            newNode.left=root;
            return newNode;
        }
        soln(root, val, 1, depth);
        return root;
    }
}