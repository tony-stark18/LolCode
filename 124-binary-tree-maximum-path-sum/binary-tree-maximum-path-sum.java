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
    public int soln(TreeNode root,int ans[]){
        if(root==null) return 0;
        int ls = Math.max(soln(root.left,ans),0);
        int rs = Math.max(soln(root.right,ans),0);
        ans[0] = Math.max(ans[0],ls+rs+root.val);
        return root.val+Math.max(ls,rs);
    }
    public int maxPathSum(TreeNode root) {
        int ans[] = new int[1];
        ans[0] = Integer.MIN_VALUE;
        soln(root,ans);
        return ans[0];
    }
}