//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            String input_line1[] = read.readLine().trim().split("\\s+");
            int k = Integer.parseInt(input_line1[0]);
            int n = Integer.parseInt(input_line1[1]);
            String input_line[] = read.readLine().trim().split("\\s+");
            int arr[]= new int[n];
            for(int i = 0; i < n; i++)
                arr[i] = Integer.parseInt(input_line[i]);
            
            Solution ob = new Solution();
            System.out.println(ob.minTime(arr,n,k));
        }
    }
}


// } Driver Code Ends


//User function Template for Java

 class Solution{
    static int helper(int[] arr, long maxTime) {
        int painters = 1;
        long currentTime = 0;
        
        for (int time : arr) {
            if (currentTime + time <= maxTime) {
                currentTime += time;
            } else {
                currentTime = time;
                painters++;
            }
        }
        return painters;
    } 
    
    static long minTime(int[] arr, int n, int k) {
        long low = 0;
        long high = 0;
        
        for (int i : arr) {
            low = Math.max(low, i);
            high += i;
        }
        
        long result = high;
        
        while (low <= high) {
            long mid = low + (high - low) / 2;
            int painters = helper(arr, mid);
            
            if (painters <= k) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
}


