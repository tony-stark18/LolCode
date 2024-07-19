//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
     
    vector<int> findUnion(int arr1[], int arr2[], int n, int m){
        set<int> ans;
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(arr1[i]==arr2[j]){
                ans.insert(arr1[i]);
                i++;
                j++;
            }
            else if(arr1[i]<arr2[j]){
                ans.insert(arr1[i]);
                i++;
            }
            else{
                ans.insert(arr2[j]);
                j++;
            }
        }
        while(i<n){
            ans.insert(arr1[i]);
            i++;
        }
        while(j<m){
            ans.insert(arr2[j]);
            j++;
        }
        vector<int> res;
        for(int i:ans){
            res.push_back(i);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends