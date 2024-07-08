//{ Driver Code Starts
import java.util.*;

class MaxLenZeroSumSub
{

    // Returns length of the maximum length subarray with 0 sum

    // Drive method
    public static void main(String arg[])
    {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T > 0)
        {
            int n = sc.nextInt();
            int arr[] = new int[n];
            for (int i = 0; i < n; i++)
                arr[i] = sc.nextInt();

            GfG g = new GfG();
            System.out.println(g.maxLen(arr, n));
            T--;
        }
    }
}
// } Driver Code Ends


class GfG
{
    int maxLen(int arr[], int n)
    {
        HashMap<Integer,Integer> hs = new HashMap<>();
        hs.put(0,-1);
        int sum = 0;
        int ans = 0;
        for(int i=0;i<arr.length;i++){
            sum+=arr[i];
            if(hs.containsKey(sum)){
                ans = Math.max(ans,i-hs.get(sum));
                // System.out.println(hs.get(sum));
            }
            else{
                hs.put(sum,i);
            }
        }
        return ans;
    }
}