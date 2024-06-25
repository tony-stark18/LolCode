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
    public int sum(TreeNode root){
        if(root==null) return 0;
        return root.val+sum(root.left)+sum(root.right);  
    }
    public void soln(TreeNode root,int sum,int prevSum[]){
        if(root==null) return;
        soln(root.left,sum,prevSum);
        int temp = root.val;
        root.val = sum-prevSum[0];
        prevSum[0]+=temp;
        soln(root.right,sum,prevSum);
    }
    public TreeNode bstToGst(TreeNode root) {
        int sum = sum(root);
        int prevSum[] = {0};
        soln(root,sum,prevSum);
        return root;
    }
}