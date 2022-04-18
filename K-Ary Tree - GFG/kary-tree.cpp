// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  long long powerMod(long long x,long long y,long long mod){
      long long res=1;
      x=x%mod;
      if(x==0) return 0;
      while(y>0){
          if(y&1) res=(res*x)%mod;
         y/=2;
          x=(x*x)%mod;
      }
      return res%mod;
  }
    long long karyTree(int k, int m) {
        // code here
        return powerMod((long long)k,(long long)m,(long long)1e9+7);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends