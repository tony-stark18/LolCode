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
    public TreeNode soln(int[] inorder, int[] postorder,HashMap<Integer,Integer> hs,int pstart,int pend,int istart,int iend){
        if(pstart<pend || istart>iend) return null;
        if(pstart==pend) return new TreeNode(postorder[pstart]);
        int mid = hs.get(postorder[pstart]);
        int rightCount = iend-mid;
        TreeNode root = new TreeNode(postorder[pstart]);
        root.left = soln(inorder,postorder,hs,pstart-rightCount-1,pend,istart,mid-1);
        root.right = soln(inorder,postorder,hs,pstart-1,pstart-rightCount,mid+1,iend);
        return root;

    }
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        HashMap<Integer,Integer> hs = new HashMap<>();
        for(int i=0;i<inorder.length;i++){
            hs.put(inorder[i],i);
        }
        return soln(inorder,postorder,hs,postorder.length-1,0,0,inorder.length-1);
    }
}