class Solution {
    public int maxFrequencyElements(int[] nums) {
        HashMap<Integer, Integer> frequencyMap = new HashMap<>();
        int maxFrequency = 0;
        int countMaxFrequency = 0;

        for (int num : nums) {
            int frequency = frequencyMap.getOrDefault(num, 0) + 1;
            frequencyMap.put(num, frequency);

            maxFrequency = Math.max(maxFrequency, frequency);
        }

        for (int key : frequencyMap.keySet()) {
            if (frequencyMap.get(key) == maxFrequency) {
                countMaxFrequency += frequencyMap.get(key);
            }
        }

        return countMaxFrequency;
    }
}