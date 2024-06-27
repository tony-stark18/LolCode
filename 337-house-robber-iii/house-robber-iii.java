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
    // Use a hashmap to store the results for memoization
    private Map<TreeNode, Integer> memoPick = new HashMap<>();
    private Map<TreeNode, Integer> memoNonPick = new HashMap<>();
    
    private int soln(TreeNode root, int prevState) {
        if (root == null) {
            return 0;
        }
        
        if (prevState == 1 && memoPick.containsKey(root)) {
            return memoPick.get(root);
        }
        if (prevState == 0 && memoNonPick.containsKey(root)) {
            return memoNonPick.get(root);
        }
        
        int pick = 0;
        int nonPick = 0;
        
        if (prevState == 0) {
            pick = root.val + soln(root.left, 1) + soln(root.right, 1);
        }
        
        nonPick = soln(root.left, 0) + soln(root.right, 0);
        
        int result = Math.max(pick, nonPick);
        if (prevState == 1) {
            memoPick.put(root, result);
        } else {
            memoNonPick.put(root, result);
        }
        
        return result;
    }
    
    public int rob(TreeNode root) {
        return soln(root, 0);
    }
}
