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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        findPath(res, sb, root);
        return res;
    }
    
    private void findPath(List<String> res, StringBuilder sb, TreeNode root){
        if(root == null) return;
        
        int len = sb.length();
        sb.append(root.val);

        if(root.left == null && root.right == null) res.add(sb.toString());

        sb.append("->");
        findPath(res, sb, root.left);
        findPath(res, sb, root.right);
        sb.setLength(len);
    }
}