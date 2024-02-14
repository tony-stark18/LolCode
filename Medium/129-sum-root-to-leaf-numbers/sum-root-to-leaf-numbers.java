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
    public void SumN(TreeNode root,int num,int arr[]){
        if(root==null){
            return;
        }
        if(root.left==null && root.right==null){
            arr[0]+=num*10+root.val;
            return;
        }
        num = num*10+root.val;
        SumN(root.left,num,arr);
        SumN(root.right,num,arr);
    }
    public int sumNumbers(TreeNode root) {
        if(root==null) return 0;
        int arr[] = new int[1];
        SumN(root,0,arr);
        return arr[0];
    }
}