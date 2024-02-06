class Solution {
    public boolean checkRecord(String s) {
        int a = 0;
        int l = 0;
        int lm = 0;

        for (char c : s.toCharArray()) {
            if (c == 'A') {
                a++;
            }

            if (c == 'L') {
                l++;
                lm = Math.max(lm, l);
            } else {
                l = 0;
            }
        }

        return a < 2 && lm < 3;
    }
}
