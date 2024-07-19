//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int,int> map;
        map.insert({0,-1});
        int ans = 0;
        int sum = 0;
        for(int i=0;i<N;i++){
            sum+=A[i];
            int rem = sum-K;
            if(map.find(rem)!=map.end()){
                ans = max(ans,i-map[rem]);
            }
            if(map.find(sum)==map.end()){
                map[sum]=i;
            }
        }
        return ans;
        
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends