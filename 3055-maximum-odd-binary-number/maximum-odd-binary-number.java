class Solution {
    public String maximumOddBinaryNumber(String s) {
        int countOne = 0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='1') countOne++;
        }
        StringBuilder ans = new StringBuilder("");
        for(int i=0;i<countOne-1;i++){
            ans.append('1');
        }
        for(int i=ans.length();i<s.length()-1;i++){
            ans.append('0');
        }
        ans.append('1');
        return ans.toString();
    }
}