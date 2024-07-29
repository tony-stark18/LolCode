class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length()==0) return 0;
        int ans = Integer.MIN_VALUE;
        char arr[] = s.toCharArray();
        int hash[] = new int[128];
        Arrays.fill(hash,-1); 
        int left = 0;
        int right = 0;
        while(right<arr.length){
            if(hash[arr[right]]!=-1){
                if(hash[arr[right]]>=left){
                    left = hash[arr[right]]+1;
                }
            }
            ans = Math.max(ans,right-left+1);
            hash[arr[right]]=right;
            right++;
        }
        return ans;
    }
}