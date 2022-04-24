// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool prime(long long n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
    long long primeProduct(long long L, long long R){
        // code here
        // fun();
        long long ans=1;
        long long mod=1e9+7;
        for(long long i=L;i<=R;i++){
            if(prime(i)) {
                ans=(ans*i)%mod;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends