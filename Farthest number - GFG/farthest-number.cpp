// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int N,vector<int> vec){
        //code here
        vector<pair<int,int>>v;
        for(int i=0;i<N;i++)
            v.push_back({vec[i],i});
        sort(v.begin(),v.end());
        vector<int>ans(N);
        int mx=v[0].second;
        ans[mx]=-1;
        for(int i=1;i<N;i++){
            if(mx>v[i].second)
                ans[v[i].second]=mx;
            else {
                mx=v[i].second;
                ans[mx]=-1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends