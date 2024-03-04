
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        boolean[] visited = new boolean[nums.length];
        backtrack(nums, result, new ArrayList<>(), visited);
        return result;
    }

    private void backtrack(int[] nums, List<List<Integer>> result, List<Integer> currentPermutation, boolean[] visited) {
        if (currentPermutation.size() == nums.length) {
            result.add(new ArrayList<>(currentPermutation));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) {
                continue; // Skip duplicates and already visited elements
            }

            visited[i] = true;
            currentPermutation.add(nums[i]);
            backtrack(nums, result, currentPermutation, visited);
            currentPermutation.remove(currentPermutation.size() - 1);
            visited[i] = false;

            // Skip consecutive duplicates
            while (i + 1 < nums.length && nums[i] == nums[i + 1]) {
                i++;
            }
        }
    }
}
