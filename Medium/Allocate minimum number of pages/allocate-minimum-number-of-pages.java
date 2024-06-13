//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
class GFG {
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		
		int t=sc.nextInt();
		
		while(t-->0)
		{
		    int n=sc.nextInt();
		    int a[]=new int[n];
		    
		    for(int i=0;i<n;i++)
		    {
		        a[i]=sc.nextInt();
		    }
		    int m=sc.nextInt();
		    Solution ob = new Solution();
		    System.out.println(ob.findPages(a,n,m));
		}
	}
}
// } Driver Code Ends


//User function Template for Java

class Solution 
{
    public static int helper(int[] A,int pages){
        int stu = 1;
        int pg  = 0;
        for(int i:A){
            if(pg+i<=pages){
                pg = pg+i;
            }
            else{
                stu++;
                pg = i;
            }
        }
        return stu;
    }
    //Function to find minimum number of pages.
    public static int findPages(int[]A,int N,int M)
    {
        if(N<M) return -1;
        int high = 0;
        int low = 0;
        for(int i:A){
            high+=i;
            low = Math.max(i,low);
        }
        while(low<=high){
            int mid = (low+high)/2;
            int stu = helper(A,mid);
            if(stu<=M){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};