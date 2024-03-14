
public class Solution {
    private void generateCombinations(String digits, HashMap<Character, String> mappings, List<String> combinations, StringBuilder current, int index) {
        // Base case: when index reaches the length of digits
        if (index == digits.length()) {
            combinations.add(current.toString()); // Add the current combination to the list
            return;
        }

        char digit = digits.charAt(index);
        String mapping = mappings.get(digit);

        // Iterate through the characters mapped to the current digit
        for (char c : mapping.toCharArray()) {
            current.append(c); // Append the character to the current combination
            generateCombinations(digits, mappings, combinations, current, index + 1); // Recursive call
            current.deleteCharAt(current.length() - 1); // Backtrack: Remove the last character
        }
    }

    public List<String> letterCombinations(String digits) {
        if (digits == null || digits.length() == 0) {
            return new ArrayList<>(); // Return an empty list if the input is empty
        }

        // Mapping of digits to corresponding characters
        HashMap<Character, String> mappings = new HashMap<>();
        mappings.put('2', "abc");
        mappings.put('3', "def");
        mappings.put('4', "ghi");
        mappings.put('5', "jkl");
        mappings.put('6', "mno");
        mappings.put('7', "pqrs");
        mappings.put('8', "tuv");
        mappings.put('9', "wxyz");

        List<String> combinations = new ArrayList<>();
        generateCombinations(digits, mappings, combinations, new StringBuilder(), 0); // Start generating combinations
        return combinations;
    }
}
