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
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null)
            return null;
        if (key > root.val) {
            root.right = deleteNode(root.right, key);
        } else if (key < root.val) {
            root.left = deleteNode(root.left, key);
        } else {
            if (root.left == null && root.right == null)
                return null;
            if (root.left == null)
                return root.right;
            if (root.right == null)
                return root.left;

            TreeNode is = getIS(root.right);
            root.val = is.val;
            root.right = deleteNode(root.right, is.val);
        }
        return root;
    }

    public TreeNode getIS(TreeNode root) {
        while (root.left != null) {
            root = root.left;
        }
        return root;
    }

    public TreeNode sabUdaDo(TreeNode root, int low, int high) {
        if (root == null){
            return null;
        }
        int val = root.val;
        root.left = sabUdaDo(root.left, low, high);
        root.right = sabUdaDo(root.right, low, high);
        if (val < low || val > high) {
            root = deleteNode(root, val);
        }
        return root;
    }

    public TreeNode trimBST(TreeNode root, int low, int high) {
        return sabUdaDo(root, low, high);
    }
}