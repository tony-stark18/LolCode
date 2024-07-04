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
            String line1[] = in.readLine().trim().split("\\s+");
            int N = Integer.parseInt(line1[0]);
            int W = Integer.parseInt(line1[1]);
            String line2[] = in.readLine().trim().split("\\s+");
            int val[] = new int[N];
            for(int i = 0;i < N;i++)
                val[i] = Integer.parseInt(line2[i]);
            String line3[] = in.readLine().trim().split("\\s+");
            int wt[] = new int[N];
            for(int i = 0;i < N;i++)
                wt[i] = Integer.parseInt(line3[i]);
                
            Solution ob = new Solution();
            System.out.println(ob.knapSack(N, W, val, wt));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    static int soln(int W,int wt[],int val[],int i,int dp[][]){
        if(i==val.length){
            return 0;
        }
        if(dp[i][W]!=-1)
            return dp[i][W];
            
            
        int nTake = soln(W,wt,val,i+1,dp);
        
        
        int take = Integer.MIN_VALUE;
        
        
        if(wt[i]<=W){
            take = val[i]+soln(W-wt[i],wt,val,i,dp);
        }
        
        return dp[i][W]=Math.max(nTake,take);
    }
    static int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[][] = new int[N][W + 1];
        for(int i=0;i<N;i++){
            Arrays.fill(dp[i],-1);
        }
        return soln(W,wt,val,0,dp);
    }
}