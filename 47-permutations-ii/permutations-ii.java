class Solution {
    public void soln(int[] nums,Set<List<Integer>> ans, List<Integer> ds,int[] visited){
        if(ds.size()==nums.length){
            ans.add(new ArrayList<>(ds));
            return;
        }
        for(int i=0;i<nums.length;i++){
            if(visited[i]==0){
                visited[i]=1;
                ds.add(nums[i]);
                soln(nums,ans,ds,visited);
                visited[i]=0;
                ds.remove(ds.size()-1);
            }
        }
    }
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> ls = new ArrayList<>();
        Set<List<Integer>> ans = new HashSet<>();
        int vis[] = new int[nums.length];
        soln(nums,ans,new ArrayList<>(),vis);
        Iterator<List<Integer>> i = ans.iterator();
        while (i.hasNext()){
            ls.add(i.next());
        }
        return ls;
     }
}