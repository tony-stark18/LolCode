class Solution {
    public String makeGood(String s) {
        if (s.length() <= 1) return s;
        StringBuilder sb = new StringBuilder(s);
        boolean flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < sb.length() - 1; i++) {
                if (Math.abs((int) sb.charAt(i) - (int) sb.charAt(i + 1)) == 32) {
                    sb.delete(i, i + 2);
                    flag = true;
                    break;
                }
            }
        }
        return sb.toString();
    }
}
