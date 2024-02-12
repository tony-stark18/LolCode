class Solution {
    public void flatten(TreeNode root) {
        while (root != null) {
            if (root.left != null) {
                TreeNode left = root.left;
                TreeNode rightMost = left;
                while (rightMost.right != null) {
                    rightMost = rightMost.right;
                }

                rightMost.right = root.right;
                root.right = left;
                root.left = null;
            }

            root = root.right;
        }
    }
}
