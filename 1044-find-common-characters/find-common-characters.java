class Solution {
    public List<String> commonChars(String[] words) {
        int n = words.length;
        int arr[][] = new int[n][26];
        for (int i = 0; i < n; i++) {
            for (char c : words[i].toCharArray()) {
                arr[i][c - 'a']++;
            }
        }
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            int count = arr[0][i];
            for (int j = 1; j < n; j++) {
                count = Math.min(count, arr[j][i]);
            }
            if (count != 0) {
                for (int k = 0; k < count; k++) {

                    ans.add(Character.toString('a' + i));
                }
            }
        }
        return ans;
    }
}