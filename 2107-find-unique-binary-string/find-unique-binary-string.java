class Solution {
    public void helper(int n,String s,int lastIndex,Set<String> st,String[] ans){
        if(!ans[0].equals("")) return;
        if(n==0){
            if(!st.contains(s)) ans[0]=s;
            return;
        }
        helper(n-1,s+"0",0,st,ans);

        if(lastIndex==0){
            helper(n-1,s+"1",1,st,ans);
        }
    }
    public String findDifferentBinaryString(String[] nums) {
        int n = nums.length;
        int len = nums[0].length();
        Set<String> st = new HashSet<String>();
        for(int i=0;i<n;i++){
            st.add(nums[i]);
        }
        String ans[] = {""};
        helper(n,"",0,st,ans);
        return ans[0];
    }
}