class Solution {
       
    public boolean isValidBST(TreeNode root) {
        return check(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    private boolean check(TreeNode root, long minValue, long maxValue) {
        if (root == null) return true;
        if (root.val <= minValue || root.val >= maxValue) return false;
        return check(root.left, minValue, root.val) && check(root.right, root.val, maxValue);
    }
    
}