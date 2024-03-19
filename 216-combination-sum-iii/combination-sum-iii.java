class Solution {
    public void soln(int k,int n,List<List<Integer>> ans,List<Integer> ds,int sum,int itr){
        if(ds.size()==k && sum==n){
            ans.add(new ArrayList<>(ds));
            return;
        }
        if(sum>n || ds.size()>k) return;
        for(int i=itr;i<=9;i++){
            ds.add(i);
            soln(k,n,ans,ds,sum+i,i+1);
            ds.remove(ds.size()-1);
        }
    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        soln(k,n,ans,new ArrayList<>(),0,1);
        return ans;
    }
}