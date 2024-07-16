/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public void depth(TreeNode root, int target, int ans[], int depth) {
        if (root == null)
            return;
        if (root.val == target) {
            ans[0] = depth;
            return;
        }
        depth(root.left, target, ans, depth + 1);
        depth(root.right, target, ans, depth + 1);
    }

    public void getPath(TreeNode root, int target, StringBuilder sb, StringBuilder path) {
        if (root == null)
            return;
        if (root.val == target) {
            sb.append(path); // Append the found path to sb
            return;
        }
        path.append('L');
        getPath(root.left, target, sb, path);
        path.setLength(path.length() - 1); // Remove the last character
        path.append('R');
        getPath(root.right, target, sb, path);
        path.setLength(path.length() - 1); // Remove the last character
    }

    public boolean soln(TreeNode root, int s, int d, StringBuilder sb) {
        if (root == null)
            return false;
        boolean leftR = soln(root.left, s, d, sb);
        boolean rightR = soln(root.right, s, d, sb);
        if (root.val == s || root.val == d) {
            if (leftR || rightR) {
                int ans[] = new int[1];
                depth(root, s, ans, 0);
                int sDepth = ans[0];
                depth(root, d, ans, 0);
                int dDepth = ans[0];
                if (dDepth < sDepth) {
                    for (int i = 0; i < (sDepth - dDepth); i++) {
                        sb.append('U');
                    }
                } else {
                    StringBuilder ssb = new StringBuilder("");
                    getPath(root, d, sb, ssb);
                }
                return false;
            }
            return true;
        } else if (leftR && rightR) {
            int ans[] = new int[1];
            depth(root, s, ans, 0);
            int sDepth = ans[0];
            for (int i = 0; i < sDepth; i++) {
                sb.append('U');
            }
            StringBuilder ssb = new StringBuilder("");
            getPath(root, d, sb,ssb);
            return false;
        }
        return leftR || rightR;
    }

    public String getDirections(TreeNode root, int s, int d) {
        int depth[] = new int[1];
        // depth(root,2,depth,0);
        // System.out.println(depth[0]);
        StringBuilder sb = new StringBuilder("");
        soln(root, s, d, sb);
        return sb.toString();
    }
}