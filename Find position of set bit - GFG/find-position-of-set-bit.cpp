// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        vector<int>v;
        int i=1;
        while(N){
            if(N%2) v.push_back(i);
            i++;
            N/=2;
        }
        if(v.size()==0 or v.size()>1) return -1;
        else return v[0];
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
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends