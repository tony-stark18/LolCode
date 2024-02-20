class Solution {
    private void soln(TreeNode root, int sum, List<List<Integer>> ans, List<Integer> ds) {
        if (root == null) return;

        ds.add(root.val);

        if (root.left == null && root.right == null && sum - root.val == 0) {
            ans.add(new ArrayList<>(ds));
        }

        soln(root.left, sum - root.val, ans, ds);
        soln(root.right, sum - root.val, ans, ds);

        ds.remove(ds.size() - 1);
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();
        soln(root, targetSum, ans, ds);
        return ans;
    }
}
