class Solution {
    public void reverse(StringBuilder s, int start, int end) {
        while (start <= end) {
            char temp = s.charAt(start);
            s.setCharAt(start, s.charAt(end));
            s.setCharAt(end, temp);
            start++;
            end--;
        }
    }

    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder(s);
        int li = 0;
        for (int i = 0; i < sb.length(); i++) {
            if (sb.charAt(i) == ' ') {
                reverse(sb, li, i - 1);
                li = i + 1;
            }
        }
        reverse(sb, li, sb.length() - 1);
        
        return sb.toString();
    }
}
