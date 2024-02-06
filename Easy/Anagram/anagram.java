//{ Driver Code Starts
import java.util.*;
import java.util.stream.*; 
import java.lang.*;
import java.io.*;

class GFG {
    
	public static void main (String[] args)throws IOException {
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while(t-->0)
		{
		    String str = br.readLine();
		    String s1 = str.split(" ")[0];
		    String s2 = str.split(" ")[1];
		    
		    Solution obj = new Solution();
		    
		    if(obj.isAnagram(s1,s2))
		    {
		        System.out.println("YES");
		    }
		    else
		    {
		         System.out.println("NO");
		    }
		    
		    
		    
		}
	}
}
// } Driver Code Ends


class Solution
{    
    //Function is to check whether two strings are anagram of each other or not.
    public static boolean isAnagram(String str1,String str2)
    {
        
        
        str1=str1.toLowerCase();
        str2=str2.toLowerCase();
        if(str1.length()==str2.length()){
            char arr1[]=str1.toCharArray();
            char arr2[]=str2.toCharArray();
            Arrays.sort(arr1);
            Arrays.sort(arr2);
            if(Arrays.equals(arr1, arr2)){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
        
    }
}
        
