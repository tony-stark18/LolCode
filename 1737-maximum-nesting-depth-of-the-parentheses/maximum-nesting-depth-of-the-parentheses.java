class Solution {
    public int maxDepth(String s) {
        int count = 0;
        int maxCount = 0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('){
                count++;
            }
            if(s.charAt(i)==')'){
                count--;
            }
            maxCount=Math.max(count,maxCount);
        }
        return maxCount;
    }
}