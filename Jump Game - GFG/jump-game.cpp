// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
        // code here
        int jumps=1;
        if(N<=1) return 1;
        if(A[0]<1) return 0;
        int steps=A[0],maxReach=A[0];
        for(int i=1;i<N;i++){
            maxReach=max(maxReach,i+A[i]);
            if(i==N-1) return 1;
            steps--;
            if(steps==0){
                jumps++;
                if(maxReach<=i) return 0;
                steps=maxReach-i;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends