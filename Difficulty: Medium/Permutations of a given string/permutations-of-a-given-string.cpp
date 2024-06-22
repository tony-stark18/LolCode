//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void soln(vector<bool> &vis,set<string> &ans,string S,string temp){
	        if(temp.length()==S.length()){
	            ans.insert(temp);
	            return;
	        }
	        for(int i=0;i<S.length();i++){
	            if(!vis[i]){
	                vis[i]=true;
	                soln(vis,ans,S,temp+S[i]);
	                vis[i]=false;
	            }
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<bool> vis(S.length(),false);
		    set<string> ans;
		    soln(vis,ans,S,"");
		    vector<string> vt;
		    set<string>::iterator itr;
		    for (itr = ans.begin(); itr != ans.end(); itr++) 
            {
                vt.push_back(*itr);
            }
		    return vt;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends