// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int mx=0,sum=0;
        for(int i=0;i<N;i++){
            mx=max(mx,arr[i]);
            sum+=arr[i];
        }
        while(mx<sum){
            int mid=mx+(sum-mx)/2;
            int piece=1,sm=0;
            for(int i=0;i<N;i++){
                if(sm+arr[i]>mid){
                    piece++;
                    sm=arr[i];
                }
                else sm+=arr[i];
            }
            if(piece>D) mx=mid+1;
            else sum=mid;
        }
        return mx;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends