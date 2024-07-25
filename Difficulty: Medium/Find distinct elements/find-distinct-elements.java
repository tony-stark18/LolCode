//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            int N = Integer.parseInt(in.readLine());
            int M[][] = new int[N][N];
            String arr[] = in.readLine().trim().split("\\s+");
            for(int i = 0;i < N*N; i++)
                M[i/N][i%N] = Integer.parseInt(arr[i]);
                
            Solution ob = new Solution();
            System.out.println(ob.distinct(M, N));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static int distinct(int M[][], int N)
    {
        Arrays.sort(M[0]);
        int count = 0;
        for(int j=0;j<N;j++){
            if(j>0 && M[0][j]==M[0][j-1]) continue;
            boolean flag=true;
            for(int i=1;i<N;i++){
                int nEq = 0;
                for(int k=0;k<N;k++){
                    if(M[0][j]!=M[i][k]){
                        nEq++;
                    }
                }
                if(nEq==N){
                    flag=false;
                    break;
                }
            }
            if(flag){
                count++;
            }
        }
        return count;
    }
}