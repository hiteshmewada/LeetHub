// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  // 2
    // 1 8
    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
        // code here
        sort(arr.begin(),arr.end());
        int ans=1,sib=0;
        for(int i=0;i<N-1;i++){
            if(i+1<N-1 and arr[i][0]==arr[i+1][0]){
                sib++;
                int b=__gcd(arr[i][1],arr[i+1][1]);
                ans=max(ans,b);
                i++;
            }
        }
        if(sib) return ans;
        return 0;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends