class Solution {
    public String reversePrefix(String word, char ch) {
        int t = -1;
        for(int i=0;i<word.length();i++){
            if(word.charAt(i)==ch) {
                t=i;
                break;
            }
        }
        if(t==-1) return word;
        StringBuilder sb = new StringBuilder(word.substring(0,t+1));
        sb.reverse();
        sb.append(word.substring(t+1,word.length()));
        return sb.toString();
    }
}