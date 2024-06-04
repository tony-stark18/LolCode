class Solution {
    public int longestPalindrome(String s) {
        HashMap<Character,Integer> hs = new HashMap<>();
        for(char c:s.toCharArray()){
            hs.put(c,hs.getOrDefault(c,0)+1);
        }
        int count = 0;
        for(int value:hs.values()){
            if(value%2==0) count+=value;
            else count+=value-1;
        }
        if(count!=s.length()) return count+1;
        return count;
    }
}