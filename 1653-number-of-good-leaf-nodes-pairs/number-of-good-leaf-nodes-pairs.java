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
    // Post-order traversal to count pairs
    public int[] dfs(TreeNode root, int distance, int[] ans) {
        if (root == null) return new int[distance + 1];
        if (root.left == null && root.right == null) {
            int[] leafDistances = new int[distance + 1];
            leafDistances[1] = 1; // Distance of 1 from the leaf itself
            return leafDistances;
        }

        int[] leftDistances = dfs(root.left, distance, ans);
        int[] rightDistances = dfs(root.right, distance, ans);

        // Count pairs
        for (int i = 1; i <= distance; i++) {
            for (int j = 1; j <= distance; j++) {
                if (i + j <= distance) {
                    ans[0] += leftDistances[i] * rightDistances[j];
                }
            }
        }

        // Aggregate distances for the current node
        int[] currentDistances = new int[distance + 1];
        for (int i = 1; i < distance; i++) {
            currentDistances[i + 1] += leftDistances[i];
            currentDistances[i + 1] += rightDistances[i];
        }

        return currentDistances;
    }

    public int countPairs(TreeNode root, int distance) {
        int[] ans = new int[1];
        dfs(root, distance, ans);
        return ans[0];
    }
}
