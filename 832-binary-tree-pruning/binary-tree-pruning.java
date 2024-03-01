class Solution {
    public int dfs(TreeNode root) {
        if (root == null) return 0;
        
        int left = dfs(root.left);
        int right = dfs(root.right);
        
        if (left == 0) {
            root.left = null;
        }
        
        if (right == 0) {
            root.right = null;
        }
        
        return left + right + root.val;
    }

    public TreeNode pruneTree(TreeNode root) {
        if (dfs(root) == 0) {
            return null;
        }
        return root;
    }
}
