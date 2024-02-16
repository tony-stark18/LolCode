class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        int n = arr.length;
        Map<Integer, Integer> hm = new HashMap<>();
        for(int i=0;i<n;i++){
            if(hm.containsKey(arr[i])){
                int f = hm.get(arr[i]);
                hm.put(arr[i],f+1);
            }
            else{
                hm.put(arr[i],1);
            }
        }
        int sz = hm.size();
        int fre[] = new int[sz];
        int itr=0;
        for (Map.Entry<Integer,Integer> mapElement : hm.entrySet()) {
            fre[itr]=mapElement.getValue();
            itr++;
        }
        
        Arrays.sort(fre);
        for(int i=0;i<sz;i++){
            System.out.println(fre[i]);
            k=k-fre[i];
            if(k==0) return sz-i-1;
            if(k<0) return sz-i;
        }
        return 0;

    }
}