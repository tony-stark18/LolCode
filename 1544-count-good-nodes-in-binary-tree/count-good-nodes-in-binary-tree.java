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
    public void dfs(TreeNode root,int maxVal,int arr[]){
        if(root==null) return;
        if(root.val>=maxVal){
            arr[0]+=1;
            maxVal = root.val;
        }
        dfs(root.left,maxVal,arr);
        dfs(root.right,maxVal,arr);
    }
    public int goodNodes(TreeNode root) {
        int arr[] = new int[1];
        dfs(root,root.val,arr);
        return arr[0];
    }
}