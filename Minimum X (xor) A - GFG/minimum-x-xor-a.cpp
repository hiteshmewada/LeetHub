// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        bitset<32>bs(a);
        int ans=0,cnt=__builtin_popcount(b);
        for(int i=31;i>=0;i--){
            if(bs[i]==1 and cnt>0){
                ans+=(1<<i);
                cnt--;
            }
        }
        for(int i=0;i<32;i++){
            if(bs[i]==0 and cnt>0){
                cnt--;
                ans+=(1<<i);
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
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends