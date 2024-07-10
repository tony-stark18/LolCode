class Solution {
    public int minOperations(String[] logs) {
        int ans = 0;
        for(String s:logs){
            if(s.equals("../")){
                ans--;
                if(ans<0) ans = 0;
            }
            else if(s.equals("./")) continue;
            else ans++;
        }
        if(ans<0) return 0;
        return ans;
    }
}