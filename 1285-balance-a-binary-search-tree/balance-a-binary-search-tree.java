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
    public void inorder(TreeNode root,List<Integer> ls){
        if(root==null) return;
        inorder(root.left,ls);
        ls.add(root.val);
        inorder(root.right,ls);
    }
    public TreeNode construct(List<Integer> ls,int left,int right){
        if(left>right) return null;
        if(left==right){
            return new TreeNode(ls.get(left));
        }
        int mid = (left+right)/2;
        TreeNode root = new TreeNode(ls.get(mid));
        root.left = construct(ls,left,mid-1);
        root.right = construct(ls,mid+1,right);
        return root;
    }
    public TreeNode balanceBST(TreeNode root) {
        List<Integer> ls = new ArrayList<>();
        inorder(root,ls);
        return construct(ls,0,ls.size()-1);
    }
}