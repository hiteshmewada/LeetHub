// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        sort(arr,arr+n);
        int ans=0, cy=0;
        string s;
        for(int i=n-1;i>=0;i--){
            ans=0;
            if(i-1>=0){
                ans=arr[i]+arr[i-1];
                i--;
                ans+=cy;
                cy=ans/10;
                s+=(ans%10)+'0';
                // cout<<s<<" ";
            }
            else{
                ans=arr[i];
                 ans+=cy;
                cy=ans/10;
                s+=(ans%10)+'0';
            }
        }
        if(cy){
            s+=(cy)+'0';
        }
        reverse(s.begin(),s.end());
        return stoll(s);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends