class Solution {
    public int diagonalSum(int[][] mat) {
       int i=0,j=0,sum =0;
       for(i=0;i<mat.length;i++){
           sum = sum + mat[i][i];
           if(i!=mat.length-i-1){
               sum = sum + mat[i][mat.length-i-1];
           } 
       }
       return sum;       
    }
}