// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int ans=INT_MIN;
        int ar[C];
        for(int i=0;i<R;i++){
            memset(ar,0,sizeof(ar));
            for(int j=i;j<R;j++){
                int sum=0;
                for(int k=0;k<C;k++){
                    ar[k]+=M[j][k];
                    sum=max(sum+ar[k],ar[k]);
                    ans=max(ans,sum);
                }
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
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends