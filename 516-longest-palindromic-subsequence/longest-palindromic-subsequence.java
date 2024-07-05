class Solution {
    public void reverse(char arr[]){
        int i=0;
        int j=arr.length-1;
        while(i<=j){
            char t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }
    public int longestPalindromeSubseq(String s) {
        char[] s1 =s.toCharArray();
        char[] s2 =s.toCharArray();
        reverse(s2);
        int n = s1.length;
        int prev[] = new int[n+1];
        int curr[] = new int[n+1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) curr[j] = 1+prev[j-1];
                else curr[j] = Math.max(prev[j],curr[j-1]);
            }
            prev = curr.clone();
        }
        return prev[n];
    }
}