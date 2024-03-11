import java.util.HashMap;

class Solution {
    public String customSortString(String order, String s) {
        HashMap<Character, Integer> charCountMap = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            charCountMap.put(c, charCountMap.getOrDefault(c, 0) + 1);
        }

        StringBuilder result = new StringBuilder();

        for (int i = 0; i < order.length(); i++) {
            char c = order.charAt(i);
            if (charCountMap.containsKey(c)) {
                int count = charCountMap.get(c);
                while (count > 0) {
                    result.append(c);
                    count--;
                }
                charCountMap.remove(c);
            }
        }

        for (char c : charCountMap.keySet()) {
            int count = charCountMap.get(c);
            while (count > 0) {
                result.append(c);
                count--;
            }
        }

        return result.toString();
    }
}
