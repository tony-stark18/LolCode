//{ Driver Code Starts
import java.util.*;
import java.io.*;
import java.lang.*;

class gfg
{
    public static void main(String args[])throws IOException
    {
        //reading input using BufferedReader class
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        
        //reading total testcases
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0)
        {
            //reading number of elements and weight
            int n = Integer.parseInt(read.readLine());
            int w = Integer.parseInt(read.readLine());
            
            int val[] = new int[n];
            int wt[] = new int[n];
            
            String st[] = read.readLine().trim().split("\\s+");
            
            //inserting the values
            for(int i = 0; i < n; i++)
              val[i] = Integer.parseInt(st[i]);
             
            String s[] = read.readLine().trim().split("\\s+"); 
            
            //inserting the weigths
            for(int i = 0; i < n; i++)
              wt[i] = Integer.parseInt(s[i]);
              
            //calling method knapSack() of class Knapsack
            System.out.println(new Solution().knapSack(w, wt, val, n));
        }
    }
}




// } Driver Code Ends


class Solution 
{ 
    static int soln(int W,int wt[],int val[],int i,int dp[][]){
        if(i==val.length-1){
            if(wt[i]<=W){
                return val[i];
            }
            return 0;
        }
        if(dp[i][W]!=-1) return dp[i][W];
        int nTake = 0+soln(W,wt,val,i+1,dp);
        int take = Integer.MIN_VALUE;
        if(wt[i]<=W){
            take = val[i]+soln(W-wt[i],wt,val,i+1,dp);
        }
        return dp[i][W]=Math.max(nTake,take);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    static int knapSack(int W, int wt[], int val[], int n) 
    { 
        int prev[] = new int[W + 1];
        int curr[] = new int[W + 1];
    
        // Initialize the prev array for the first item
        for (int w = wt[0]; w <= W; w++) {
            prev[w] = val[0];
        }
    
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= W; j++) {
                int nTake = prev[j];  // Not taking the item
                int take = Integer.MIN_VALUE;
                if (wt[i] <= j) {
                    take = val[i] + prev[j - wt[i]];  // Taking the item
                }
                curr[j] = Math.max(nTake, take);
            }
            // Copy current row to previous row for the next iteration
            prev = curr.clone();
        }
        return prev[W];
    }
 
}


