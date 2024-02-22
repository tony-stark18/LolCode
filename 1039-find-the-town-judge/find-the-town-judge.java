class Solution {
    public int findJudge(int n, int[][] trust) {
        int size = trust.length;
        if(n==1) return 1;
        if(size==0) return -1;
        int arr1[] = new int[n+1];
        int arr2[] = new int[n+1];
        for(int i=0;i<size;i++){
            arr1[trust[i][0]]++;
            arr2[trust[i][1]]++;
        }
        int num=0;
        int cnt =0;
        for(int i=1;i<=n;i++){
            if(arr1[i]==0 && arr2[i]!=0){
                num=i;
                cnt++;   
            }
        }
        if(cnt!=1) return -1;
        if(arr2[num]==n-1) return num;
        return -1;
    }
}