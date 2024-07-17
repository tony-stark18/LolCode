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
    public TreeNode soln(TreeNode root, HashSet<Integer> hs,List<TreeNode> ans){
        if(root==null) return null;
        root.left = soln(root.left,hs,ans);
        root.right = soln(root.right,hs,ans);
        if(hs.contains(root.val)){
            if(root.left!=null) ans.add(root.left);
            if(root.right!=null) ans.add(root.right);
            return null;
        }
        return root;
    }
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        List<TreeNode> ans = new ArrayList<>();
        HashSet<Integer> hs = new HashSet<>();
        for(int i:to_delete){
            hs.add(i);
        }
        root = soln(root,hs,ans);
        if(root!=null)
            ans.add(root);
        return ans;
    }
}