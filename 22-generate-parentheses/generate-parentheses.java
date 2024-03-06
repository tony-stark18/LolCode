class Solution {
    public void soln(List<String> ans,String s,int n,int k,int l){
        if(s.length()==2*n){
            ans.add(s);
            return;
        }
        if(k<n){
            soln(ans,s+"(",n,k+1,l);
        }
        if(k>l) soln(ans,s+")",n,k,l+1);
    }
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        soln(ans,"",n,0,0);
        return ans;
    }
}