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
    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        int lv = root.val;
        q.add(root);
        q.add(null);
        while(!q.isEmpty()){
            TreeNode node = q.remove();
            if(node==null){
                if(q.isEmpty()){
                    break;
                }
                else{
                    lv = q.peek().val;
                    q.add(null);   
                }
            }
            else{
                if(node.left!=null) q.add(node.left);
                if(node.right!=null) q.add(node.right);
            }
        }
        return lv;
    }
}