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
    String ans = "";
    public String smallestFromLeaf(TreeNode root) {
        dfs(root,"");
        return ans;
    }
    public void dfs(TreeNode root,String s){
        if(s==null) return;
        s=(char)(root.val+'a')+s;
        if(root.left==null && root.right==null){
            if(ans.isEmpty() || ans.compareTo(s)>0){
                ans = s;
            }
        }
        if(root.left!=null){
            dfs(root.left,s);
        }
        if(root.right!=null){
            dfs(root.right,s);
        }
    }
}