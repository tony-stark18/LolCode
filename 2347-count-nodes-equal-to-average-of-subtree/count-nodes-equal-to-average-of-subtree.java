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
    public int count = 0;
    public int[] soln(TreeNode root){
        if(root==null){
            return new int[2];
        }
        int[] arr1 = soln(root.left);
        int[] arr2 = soln(root.right);
        int arr[] = new int[2];
        arr[0]=arr1[0]+arr2[0]+root.val;
        arr[1]=arr1[1]+arr2[1]+1;
        if(arr[0]/arr[1]==root.val){
            count++;
            System.out.println(root.val);
        }
        return arr;
    }
    public int averageOfSubtree(TreeNode root) {
        soln(root);
        return count;
    }
}