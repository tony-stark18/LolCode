class Solution {

    int leftmost = 0;
    int leftmostrow = -1;
    void visit(TreeNode root, int depth) {
        if (root == null) return;
        if (depth > leftmostrow) {
            leftmost = root.val;
            leftmostrow = depth;
        }
        visit(root.left, depth+1);
        visit(root.right, depth+1);
    }

    public int findBottomLeftValue(TreeNode root) {
        visit(root, 0)    ;
        return leftmost;
    }
}