class Solution {
    public int findJudge(int n, int[][] trust) {
        int size = trust.length;
        if(n==1) return 1;
        if(size==0) return -1;
        int arr1[] = new int[n+1];
        for(int i=0;i<size;i++){
            arr1[trust[i][0]]--;
            arr1[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(arr1[i]==n-1) return i;
        }
        return -1;
    }
}