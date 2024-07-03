//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int n;
            n = Integer.parseInt(br.readLine());
            
            
            int d;
            d = Integer.parseInt(br.readLine());
            
            
            int[] arr = IntArray.input(br, n);
            
            Solution obj = new Solution();
            int res = obj.countPartitions(n, d, arr);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends



class Solution {
    static int mod = 1000000007;

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

    public static int countPartitions(int n, int d, int[] arr) {
        long sum = 0;
        for (int i : arr) sum += i;
        if ((sum + d) % 2 != 0) return 0; // Ensuring valid partition
        int target = (int) (sum + d) / 2;
        int dp[][] = new int[n][target + 1];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return f(arr, n - 1, target, dp);
    }
}
        
