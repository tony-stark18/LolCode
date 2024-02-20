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
    public void lorder(TreeNode root,List<Integer> ds,Stack<List<Integer>> st){
        if(root==null) return;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        q.add(null);
        while(!q.isEmpty()){
            TreeNode node = q.remove();
            if(node==null){
                st.push(new ArrayList<>(ds));
                ds.clear();
                if(q.isEmpty()) break;
                q.add(null);
            }
            else{
                ds.add(node.val);
                if(node.left!=null) q.add(node.left);
                if(node.right!=null) q.add(node.right);
            }
        }
    }
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();
        Stack<List<Integer>> st = new Stack();
        lorder(root,ds,st);
        while(!st.isEmpty()){
            ans.add(st.pop());
        }
        return ans;
    }
}