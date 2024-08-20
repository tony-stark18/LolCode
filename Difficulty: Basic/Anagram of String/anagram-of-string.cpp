//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2)
{
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    int ptr1 = 0;
    int ptr2 = 0;
    int count = 0;
    while(ptr1<str1.length() && ptr2<str2.length()){
        if(str1[ptr1]==str2[ptr2]){
            ptr1++;
            ptr2++;
        }
        else if(str1[ptr1]<str2[ptr2]){
            count++;
            ptr1++;
        }
        else{
            count++;
            ptr2++;
        }
    }
    count+=str1.length()-ptr1+str2.length()-ptr2;
    return count;
}