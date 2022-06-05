// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long buzzTime(long n, long m, long l, long h[], long a[])
    {
        // code here
        long low=0,high=max(l,m),ans=0;
        while(low<=high){
            long mid=low+(high-low)/2;
            long fast=0;
            for(long i=0;i<n;i++){
                if(h[i]+mid*a[i]>=l) fast+=h[i]+a[i]*mid;
            }
            if(fast>=m){
                ans=mid;high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
        // int k=0;
        // vector<pair<long long,long long>>v;
        // for(int i=0;i<n;i++){
        //     if(h[i]>=l) k+=h[i];
        //     h[i]+=a[i];
        //     v.push_back({h[i],a[i]});
        // }
        // if(k>=m) return 1;
        // sort(v.begin(),v.end());
        // int pre[n]={0};
        // for(int i=0;i<n;i++){
        //     pre[i]=v[i].first+i==0?0:pre[i-1];
        // }
        // for(int i=0;i<n;i++)
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends