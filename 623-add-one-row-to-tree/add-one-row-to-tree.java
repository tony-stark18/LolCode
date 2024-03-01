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
    public void dfs(TreeNode root,int val,int depthG,int depthR){
        if(root==null) return;
        if(depthR==depthG-1){
            TreeNode ln = root.left;
            TreeNode rn = root.right;
            root.left = new TreeNode(val);
            root.right = new TreeNode(val);
            root.left.left = ln;
            root.right.right = rn;
        }
        dfs(root.left,val,depthG,depthR+1);
        dfs(root.right,val,depthG,depthR+1);
    }
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(depth==1){
            TreeNode newNode = new TreeNode(val);
            newNode.left=root;
            return newNode;
        }
        dfs(root,val,depth,1);
        return root;
    }
}