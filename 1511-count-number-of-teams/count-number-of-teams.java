class Solution {
    public int numTeams(int[] rating) {
        int n = rating.length;
        int leftGreater[] = new int[n];
        int leftSmaller[] = new int[n];
        int rightGreater[] = new int[n];
        int rightSmaller[] = new int[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i]){
                    leftSmaller[i]++;
                }
                else if(rating[j]>rating[i]){
                    leftGreater[i]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(rating[j]>rating[i]){
                    rightGreater[i]++;
                }
                else if(rating[j]<rating[i]){
                    rightSmaller[i]++;
                }
            }
        }
        int  count = 0;
        for(int i=0;i<n;i++){
            count+=(leftSmaller[i]*rightGreater[i])+(leftGreater[i]*rightSmaller[i]);
        }
        return count;
    }
}