import java.util.HashSet;
import java.util.List;

class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        HashSet<String> dict = new HashSet<>(dictionary);
        String st[] = sentence.split(" ");
        StringBuilder ans = new StringBuilder();
        for (String word : st) {
            StringBuilder sb = new StringBuilder();
            boolean found = false;
            for (char c : word.toCharArray()) {
                sb.append(c);
                if (dict.contains(sb.toString())) {
                    ans.append(sb).append(" ");
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans.append(word).append(" ");
            }
        }
        // Remove the trailing space
        return ans.toString().trim();
    }
}
