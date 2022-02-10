// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    
    void sortBySetBitCount(int arr[], int n)
    {
        vector<int>vec;
        for(int i=0;i<n;i++) vec.push_back(arr[i]);
         vector<pair<int,int>>v;
         for(int i=0;i<n;i++){
             int a=arr[i],bit=0;
             while(a){
                 if(a%2) bit++;
                 a=a>>1;
             }
             v.push_back({i,bit});
         }
         sort(v.begin(),v.end(),[&](const pair<int,int>&a,const pair<int,int>&b){
            if(a.second==b.second) return b.first>a.first;
            return a.second>b.second;
         });
         for(int i=0;i<n;i++){
             arr[i]=vec[v[i].first];
         }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends