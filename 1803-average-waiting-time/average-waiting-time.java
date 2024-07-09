class Solution {
    public double averageWaitingTime(int[][] customers) {
        int timePassed = 0;
        int n = customers.length;
        double wt = 0;
        for(int i=0;i<n;i++){
            if(customers[i][0]>timePassed) timePassed = customers[i][0]+customers[i][1];
            else timePassed +=customers[i][1];
            wt += timePassed-customers[i][0];
        }
        return wt/n;
    }
}