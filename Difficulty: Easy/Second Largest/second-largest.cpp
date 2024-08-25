//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        // Code Here
        int largest = arr[0];
        int n=arr.size();
        
        for(int i=0; i<n; i++){
            if(arr[i]> largest){
                largest = arr[i];
            }
        }
        
        
        int secondl = -1;
        
        for(int j =0; j<n; j++){
            if(arr[j] == largest)
                continue;
            if(arr[j] > secondl){
                secondl = arr[j];
            }
            
        }

        return secondl;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends