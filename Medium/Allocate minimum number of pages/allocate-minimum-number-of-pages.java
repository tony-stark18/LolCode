//{ Driver Code Starts
// Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int a[] = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            int m = sc.nextInt();
            Solution ob = new Solution();
            System.out.println(ob.findPages(n, a, m));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    // Function to find minimum number of pages.
    public static int helper(int pages,int[] A){
        int stu=0;
        int pg = 0;
        for(int i:A){
            if(pg+i<=pages){
                pg+=i;
            }
            else{
                stu++;
                pg=i;
            }
        }
        return stu+1;
    }
    public static long findPages(int N, int[] A, int M) {
        if(M>N) return -1;
        int low = 0;
        int high = 0;
        for(int i:A){
            low=Math.max(low,i);
            high+=i;
        }
        while(low<=high){
            int mid = (low+high)/2;
            int stu = helper(mid,A);
            if(stu<=M){
                high=mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};