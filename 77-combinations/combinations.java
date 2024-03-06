class Solution {
    public void soln(List<List<Integer>> ans, int n,int k,List<Integer> ds,int lastN){
        if(ds.size()==k){
            ans.add(new ArrayList<>(ds));
            return;
        }
        for(int i=lastN+1;i<=n;i++){
            ds.add(i);
            soln(ans,n,k,ds,i);
            ds.remove(ds.size()-1);
        }
    }
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        soln(ans,n,k,new ArrayList<>(),0);
        return ans;
    }
}