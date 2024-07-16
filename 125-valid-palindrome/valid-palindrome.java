class Solution {
    public boolean isPalindrome(String s) {
        List<Character> ls = new ArrayList<>();
        char arr[] = s.toUpperCase().toCharArray();
        for(int i=0;i<arr.length;i++){
            char ch=arr[i];
            if((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z')){
                ls.add(ch);
            }
        }
        // System.out.println(sb);
        for(int i=0;i<ls.size()/2;i++){
            if(ls.get(i)!=ls.get(ls.size()-i-1)){
                return false;
            }
        }
        return true;
    }

}