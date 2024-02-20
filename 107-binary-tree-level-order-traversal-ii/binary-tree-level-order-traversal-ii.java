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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        dfs(root, 0, ans);
        Collections.reverse(ans);
        return ans;
    }
    public void dfs(TreeNode node, int depth, List<List<Integer>> ans){
        if(node == null)  return;
        if(depth == ans.size())  ans.add(new ArrayList<>());
        ans.get(depth).add(node.val);
        dfs(node.left, depth+1, ans);
        dfs(node.right, depth+1, ans);
    }
}