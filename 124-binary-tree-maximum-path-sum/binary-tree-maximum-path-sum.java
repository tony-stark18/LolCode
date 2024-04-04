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
    private int soln(TreeNode root,int[] max){
        if(root==null) return 0;
        int ls = Math.max(soln(root.left,max),0);
        int rs = Math.max(soln(root.right,max),0);

        int res = root.val+ls+rs;
        max[0]=Math.max(max[0],res);
        return root.val+Math.max(ls,rs);
    }
    public int maxPathSum(TreeNode root) {
        int arr[] = new int[1];
        arr[0]=Integer.MIN_VALUE;
        soln(root,arr);
        return arr[0];
    }
}