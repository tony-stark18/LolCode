//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
   	long long int prime_Sum(int n){
   	    vector<int> is_prime(n+1,1);
   	    for(int i=2;i<=sqrt(n);i++){
   	        for(int j=2;i*j<=n;j++){
   	            is_prime[i*j]=0;
   	        }
   	    }
   	    long long int sum = 0;
   	    for(int i=2;i<=n;i++){
   	        if(is_prime[i]) sum+=i;
   	    }
   	    return sum;
   	}    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		long long int ans = ob.prime_Sum(n);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends