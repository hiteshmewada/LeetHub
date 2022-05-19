// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        int ans=0;
        int n=A.size(),a=B.size();
        if(n!=a) return -1;
        unordered_map<char,int>mp1,mp2;
        for(int i=0;i<n;i++){
            mp1[A[i]]++;
            mp2[B[i]]++;
        }
        if(mp1!=mp2) return -1;
        int i=n-1,j=n-1;
        while(i>=0 and j>=0){
            if(A[i]==B[j]) i--,j--;
            else ans++,i--;
        }
        return ans;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends