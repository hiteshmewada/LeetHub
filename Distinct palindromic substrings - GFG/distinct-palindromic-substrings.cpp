// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string s) {
        // code here
        int n=s.size();
        set<string>st;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=1;i<=n;i++){
            for(int j=i-1;j<n;j++){
                int start=j-i+1,end=j;
                if(s[start]==s[end] and (start+1>end-1 or dp[start+1][end-1])){
                    dp[start][end]=true;
                    string p=s.substr(start,end-start+1);
                    st.insert(p);
                }
            }
        }
        return st.size();
    }
};

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends