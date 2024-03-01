class Solution {
    public char findTheDifference(String s, String t) {
       int sSum=0;
       int tSum=0;
       for(char w : s.toCharArray()){
            sSum=sSum+w;
        }
        for(char w : t.toCharArray()){
            tSum=tSum+w;
        }
        int result = tSum - sSum;
        return (char) result;
    }
}