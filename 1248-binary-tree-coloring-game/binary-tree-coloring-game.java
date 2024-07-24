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
    public int countNodes(TreeNode root){
        if(root==null) return 0;
        return 1+countNodes(root.left)+countNodes(root.right);
    }
    public void helper(TreeNode root,int x,int nodes[]){
        if(root==null) return;
        if(root.val==x){
            nodes[0] = countNodes(root.left);
            nodes[1] = countNodes(root.right);
            return;
        }
        helper(root.left,x,nodes);
        helper(root.right,x,nodes);
    }
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        int arr[]= new int[2];
        helper(root,x,arr);
        int left = arr[0];
        int right = arr[1];
        int rest = n-1-left-right;
        return (rest>left+right || left>rest+right || right>left+rest);
    }
}