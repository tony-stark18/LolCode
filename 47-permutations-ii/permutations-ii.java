class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Set<List<Integer>> resultSet = new HashSet<>();
        backtrack(nums, resultSet, new ArrayList<>(), new boolean[nums.length]);
        result.addAll(resultSet);
        return result;
    }

    private void backtrack(int[] nums, Set<List<Integer>> resultSet, List<Integer> currentPermutation, boolean[] visited) {
        if (currentPermutation.size() == nums.length) {
            resultSet.add(new ArrayList<>(currentPermutation));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) {
                continue; // Skip duplicates and already visited elements
            }

            visited[i] = true;
            currentPermutation.add(nums[i]);
            backtrack(nums, resultSet, currentPermutation, visited);
            currentPermutation.remove(currentPermutation.size() - 1);
            visited[i] = false;
        }
    }
}
