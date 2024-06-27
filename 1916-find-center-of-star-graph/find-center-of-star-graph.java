class Solution {
    public int findCenter(int[][] edges) {
        HashMap<Integer,Integer> hs = new HashMap<>();
        for(int i=0;i<edges.length;i++){
            hs.put(edges[i][0],hs.getOrDefault(edges[i][0],0)+1);
            hs.put(edges[i][1],hs.getOrDefault(edges[i][1],0)+1);
        }
        int n = hs.size();
        for(int i:hs.keySet()){
            if(hs.get(i)==n-1) return i;
        }
        return -1;
    }
}