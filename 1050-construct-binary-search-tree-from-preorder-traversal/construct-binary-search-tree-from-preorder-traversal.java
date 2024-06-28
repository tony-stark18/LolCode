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
    public TreeNode bstFromPreorder(int[] p) {
        TreeNode root = new TreeNode(p[0]);
        Stack<TreeNode> st = new Stack<>();
        st.push(root);
        int ind = 1;
        while(ind<p.length){
            TreeNode t = st.peek();
            if(p[ind]<t.val){
                t.left = new TreeNode(p[ind]);
                st.push(t.left);
            }
            else{
                while(!st.isEmpty() && p[ind]>st.peek().val){
                    t=st.pop();
                }
                t.right = new TreeNode(p[ind]);
                st.push(t.right);
            }
            ind++;
        }
        return root;
    }
}