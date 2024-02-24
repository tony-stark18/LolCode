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
    public List<Integer> largestValues(TreeNode root) {
        List<Integer> ls = new ArrayList<>();
        if(root==null) return ls;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root); 
        q.add(null);
        int mx = Integer.MIN_VALUE;
        while(!q.isEmpty()){
            TreeNode node = q.remove();
            if(node==null){
                ls.add(mx);
                mx = Integer.MIN_VALUE;

                if(q.isEmpty()){
                    break;
                }
                q.add(null);
            }
            else{
                mx = Math.max(mx,node.val);
                if(node.left!=null) q.add(node.left);
                if(node.right!=null) q.add(node.right);
            }
        }
        return ls;
    }
}