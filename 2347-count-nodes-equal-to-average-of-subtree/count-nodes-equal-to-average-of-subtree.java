class Solution {
    private int count = 0;
    
    private int[] calculateSumAndCount(TreeNode root) {
        if (root == null) {
            return new int[]{0, 0};
        }
        
        int[] left = calculateSumAndCount(root.left);
        int[] right = calculateSumAndCount(root.right);
        
        int sum = left[0] + right[0] + root.val;
        int totalCount = left[1] + right[1] + 1;
        
        if (sum / totalCount == root.val) {
            count++;
        }
        
        return new int[]{sum, totalCount};
    }
    
    public int averageOfSubtree(TreeNode root) {
        calculateSumAndCount(root);
        return count;
    }
}
