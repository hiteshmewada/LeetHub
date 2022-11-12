//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[102][102];
    int mcm(int arr[], int st, int end){
        if(st>=end) return 0;
        if(dp[st][end]!=-1) return dp[st][end];
        int mn=INT_MAX;
        for(int i=st;i<end;i++){
            int temp=mcm(arr,st,i)+mcm(arr,i+1,end)
            +arr[i]*arr[st-1]*arr[end];
            mn=min(mn,temp);
        }
        return dp[st][end]=mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return mcm(arr,1,N-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends