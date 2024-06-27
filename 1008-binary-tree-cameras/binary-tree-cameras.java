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
    // Constants to represent the state of the nodes
    private static final int NOT_NEEDED = 0;
    private static final int NEED_CAMERA = 1;
    private static final int HAS_CAMERA = 2;
    
    private int needCover(TreeNode root, int[] cameras) {
        if (root == null) {
            return NOT_NEEDED;
        }
        
        int left = needCover(root.left, cameras);
        int right = needCover(root.right, cameras);
        
        if (left == NEED_CAMERA || right == NEED_CAMERA) {
            cameras[0]++;
            return HAS_CAMERA;
        }
        
        if (left == HAS_CAMERA || right == HAS_CAMERA) {
            return NOT_NEEDED;
        }
        
        return NEED_CAMERA;
    }
    public int minCameraCover(TreeNode root) {
        int[] cameras = new int[1];
        if (needCover(root, cameras) == NEED_CAMERA) {
            cameras[0]++;
        }
        return cameras[0];
    }

}
