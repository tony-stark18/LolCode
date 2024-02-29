import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public boolean isEvenOddTree(TreeNode root) {
        if (root == null) {
            return false; // Handle the case where the tree is empty
        }

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        q.add(null);
        int level = 0;
        int lastValue = (level % 2 == 0) ? Integer.MIN_VALUE : Integer.MAX_VALUE;

        while (!q.isEmpty()) {
            TreeNode node = q.poll();

            if (node == null) {
                if (q.isEmpty()) break;
                level++;
                q.add(null);
                lastValue = (level % 2 == 0) ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            } else {
                if ((level % 2 == 0 && (node.val % 2 == 0 || lastValue >= node.val)) ||
                    (level % 2 != 0 && (node.val % 2 != 0 || lastValue <= node.val))) {
                    return false;
                }

                lastValue = node.val;

                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }
        }

        return true;
    }
}
