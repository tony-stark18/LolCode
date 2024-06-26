//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t;
        t = sc.nextInt();
        while (t-- > 0) {

            int n;
            n = sc.nextInt();

            int k;
            k = sc.nextInt();

            int[] v = new int[n];
            for (int i = 0; i < n; i++) v[i] = sc.nextInt();

            Solution obj = new Solution();
            int res = obj.solve(n, k, v);

            System.out.println(res);
        }
    }
}

// } Driver Code Ends


// User function Template for Java
class Solution {
    public static boolean possible(int[] stalls,int k,int dist,int n){
        k--;
        int lp = 0;
        for(int i=1;i<n;i++){
            if(stalls[i]-stalls[lp]>=dist){
                k--;
                lp=i;
            }
            if(k==0) return true;
        }
        return false;
    }
    public static int solve(int n, int k, int[] stalls) {
        Arrays.sort(stalls);
        int low = 1;
        int high = stalls[n-1]-stalls[0];
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(stalls,k,mid,n)){
                ans = mid;
                // System.out.println(ans);
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
}