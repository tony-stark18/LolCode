//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int N = sc.nextInt();
            int[] arr = new int[N];
            for (int i = 0; i < N; i++) {
                arr[i] = sc.nextInt();
            }
            Solution obj = new Solution();
            ArrayList<Integer> ans = obj.longestIncreasingSubsequence(N, arr);
            for (int i = 0; i < ans.size(); i++) {
                System.out.print(ans.get(i) + " ");
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    public ArrayList<Integer> longestIncreasingSubsequence(int n, int nums[]) {
        // int n = nums.length;
        int hash[] = new int[n];
        int dp[] = new int[n];
        Arrays.fill(dp,1);
        for (int i = 0; i < n; i++) {
            hash[i] = i; // initialize hash array
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j; // store the predecessor index
                }
            }
        } 
        int ind = 0; 
        int max = 0;
        for(int i=0;i<n;i++){
            if(dp[i]>max){
                max = dp[i];
                ind = i;
            }
        }
        ArrayList<Integer> ans = new ArrayList<>();
        ans.add(nums[ind]);
        while(hash[ind]!=ind){
            ind = hash[ind];
            ans.add(nums[ind]);
        }
        Collections.reverse(ans);
        return ans;
    }
}
