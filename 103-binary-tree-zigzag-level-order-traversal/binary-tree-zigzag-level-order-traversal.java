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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ls = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        if(root==null) return ls;
        q.add(root);
        boolean flag = true;
        while(!q.isEmpty()){
            int sz = q.size();
            ArrayList < Integer > subls = new ArrayList <>();
            for(int i=0;i<sz;i++){
                TreeNode node = q.remove();
                if(node.left!=null) q.add(node.left);
                if(node.right!=null) q.add(node.right);
                if(flag) subls.add(node.val);
                else subls.add(0,node.val);
            }
            flag = !flag;
            ls.add(subls);
        }
        return ls;
    }
}