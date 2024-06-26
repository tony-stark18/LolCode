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
    public TreeNode soln(HashMap<Integer,Integer> in,int[] preorder, int[] inorder,int pleft,int pright,int ileft,int iright){
        if(pleft>pright || ileft>iright) return null;
        int midIndex = in.get(preorder[pleft]);
        TreeNode root = new TreeNode(preorder[pleft]);
        int range = midIndex - ileft;
        root.left = soln(in,preorder,inorder,pleft+1,pleft+range,ileft,midIndex-1);
        root.right = soln(in,preorder,inorder,pleft+1+range,pright,midIndex+1,iright);
        return root;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length;
        HashMap<Integer,Integer> in = new HashMap<>();
        for(int i=0;i<n;i++){
            in.put(inorder[i],i);
        }
        return soln(in,preorder,inorder,0,n-1,0,n-1);
    }
}