// class TreeNode {
//     int val;
//     TreeNode left;
//     TreeNode right;
//     TreeNode() {}
//     TreeNode(int val) { this.val = val; }
//     TreeNode(int val, TreeNode left, TreeNode right) {
//         this.val = val;
//         this.left = left;
//         this.right = right;
//     }
// }

class Solution {
    String ans = "";
    
    public String smallestFromLeaf(TreeNode root) {
        dfs(root, new StringBuilder());
        return ans;
    }
    
    public void dfs(TreeNode root, StringBuilder sb) {
        if (root == null) return;
        
        sb.append((char) (root.val + 'a'));
        
        if (root.left == null && root.right == null) {
            String s = sb.reverse().toString();
            sb.reverse(); // Revert StringBuilder back to the original state
            if (ans.isEmpty() || s.compareTo(ans) < 0) {
                ans = s;
            }
        }
        
        dfs(root.left, sb);
        dfs(root.right, sb);
        
        sb.deleteCharAt(sb.length() - 1); // Remove the last character
    }
}
