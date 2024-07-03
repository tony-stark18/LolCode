//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    int sum = sc.nextInt();
                    int arr[] = new int[n];
                    for(int i = 0;i<n;i++)
                    arr[i] = sc.nextInt();
                    
                    Solution ob = new Solution();
                    System.out.println(ob.perfectSum(arr,n,sum));
                }
        }
}    
// } Driver Code Ends


class Solution{

	static final int mod = 1000000007;
    static int f(int arr[], int ind, int target, int dp[][]) {
        if (ind == 0){
            if(target==0 && arr[0]==0) return 2;
            if(target==0 || arr[0]==target) return 1;
            return 0;
        }
        if (ind < 0) return 0;
        if (dp[ind][target] != -1) return dp[ind][target];
        int nTake = f(arr, ind - 1, target, dp) % mod;
        int take = 0;
        if (arr[ind] <= target) {
            take = f(arr, ind - 1, target - arr[ind], dp) % mod;
        }
        dp[ind][target] = (take + nTake) % mod;
        return dp[ind][target];
    }
    public int perfectSum(int arr[], int n, int sum) {
        int[][] dp = new int[n][sum+1];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i],-1);  
        }
        
        return f(arr,n-1,sum,dp);
    }
}