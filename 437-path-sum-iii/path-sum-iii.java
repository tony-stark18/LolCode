import java.util.HashMap;
import java.util.Map;

class Solution {
    void dfs(TreeNode root, long currentSum, int targetSum, Map<Long, Integer> sumFreq, int[] count) {
        if (root == null)
            return;

        currentSum += root.val;

        if (sumFreq.containsKey(currentSum - targetSum)) {
            count[0] += sumFreq.get(currentSum - targetSum);
        }

        sumFreq.put(currentSum, sumFreq.getOrDefault(currentSum, 0) + 1);

        dfs(root.left, currentSum, targetSum, sumFreq, count);
        dfs(root.right, currentSum, targetSum, sumFreq, count);

        sumFreq.put(currentSum, sumFreq.get(currentSum) - 1);
    }

    public int pathSum(TreeNode root, int targetSum) {
        Map<Long, Integer> sumFreq = new HashMap<>();
        sumFreq.put(0L, 1); // Initialize with a dummy value for the root
        int[] count = new int[]{0};

        dfs(root, 0L, targetSum, sumFreq, count);
        return count[0];
    }
}
