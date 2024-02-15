class Solution {
    public boolean isPalindrom(String s) {
        int i = 0;
        int j = s.length() - 1;
        while (i <= j) {
            if (s.charAt(i) != s.charAt(j))
                return false;
            i++;
            j--;
        }
        return true;
    }

    public int countSubstrings(String s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j <= i; j++) {
                if (isPalindrom(s.substring(j, i + 1)))
                    cnt++;
            }
        }
        return cnt;
    }
}
