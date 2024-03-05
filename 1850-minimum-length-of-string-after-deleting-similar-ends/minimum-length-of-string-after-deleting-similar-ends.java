class Solution {
    public int minimumLength(String s) {
        int left = 0;
        int right = s.length()-1;
        while(left<=right){
            if(s.charAt(left)!=s.charAt(right)) return right-left+1;
            if(left==right) return 1;
            char c = s.charAt(left);
            while(left<=right && s.charAt(left)==c){
                left++;
            }
            while(left<=right && s.charAt(right)==c){
                right--;
            }
        }
        return right-left+1;
    }
}