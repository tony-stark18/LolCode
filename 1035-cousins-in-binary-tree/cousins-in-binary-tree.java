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
    public void dfs(TreeNode root,int arr[],int parent,int depth,int x,int y){
        if(root==null) return;
        if(root.val==x){
            arr[0] = depth;
            arr[1] = parent;
        }
        if(root.val==y){
            arr[2] = depth;
            arr[3] = parent;
        }
        dfs(root.left,arr,root.val,depth+1,x,y);
        dfs(root.right,arr,root.val,depth+1,x,y);
    }
    public boolean isCousins(TreeNode root, int x, int y) {
        int arr[] = new int[4];
        dfs(root,arr,root.val,1,x,y);
        return arr[0]==arr[2] && arr[1]!=arr[3];
    }
}