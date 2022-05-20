// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
        // code here
        int ar[26]={0};
        for(int i=0;i<26;i++){
            ar[S1[i]-'a']=i;
        }
        int ans=0;
        for(int i=0;i<S2.size();i++){
            if(i==0){
                ans+=ar[S2[i]-'a'];
            }
            else{
                ans+=abs(ar[S2[i-1]-'a']-ar[S2[i]-'a']);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends