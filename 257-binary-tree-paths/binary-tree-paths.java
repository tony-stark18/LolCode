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
    public void soln(TreeNode root,List<String> ans,String s){
        if(root==null){
            return;
        }
        if(root.left==null && root.right==null){
            ans.add(s+Integer.toString(root.val));
            return;
        }
        soln(root.left,ans,s+Integer.toString(root.val)+"->");
        soln(root.right,ans,s+Integer.toString(root.val)+"->");
    }
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans = new ArrayList<>();
        if(root==null) return ans;
        String s = "";
        soln(root,ans,s);
        return ans;
    }
}