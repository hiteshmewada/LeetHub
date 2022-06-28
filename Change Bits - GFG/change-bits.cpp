// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> changeBits(int N) {
        // code here
        int f=0;
        int ans=0,ori=N,i=0;
        while(N){
            if(N%2==0){
                
                    ans+=(1<<i);
                
            }
            else ans+=(1<<i);
            i++;
            N/=2;
        }
        return {ans-ori,ans};
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends