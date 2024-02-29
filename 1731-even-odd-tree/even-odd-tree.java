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
    public boolean isEvenOddTree(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        int level =0;
        q.add(root);
        q.add(null);
        int lastValue = Integer.MIN_VALUE;
        while(!q.isEmpty()){
            TreeNode node = q.remove();
            if(node==null){
                if(q.isEmpty()) break;
                level++;
                q.add(null);
                lastValue = (level % 2 == 0) ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
            else{
                if(level%2==0){
                    if(node.val%2==0 || lastValue>=node.val) return false;
                }
                if(level%2!=0){
                    if(node.val%2!=0 || lastValue<=node.val) return false;
                }
                lastValue = node.val;
                if(node.left!=null) q.add(node.left);
                if(node.right!=null) q.add(node.right);
            }
        }
        return true;
    }
}