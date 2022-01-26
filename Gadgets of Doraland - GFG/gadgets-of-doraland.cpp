// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    vector<int> TopK(vector<int>& array, int k)
    {
        // code here
        unordered_map<int,int>mp;
        for(int i=0;i<array.size();i++){
            mp[array[i]]++;
        }
        
        int j=0;
        vector<int>ans;
        vector<pair<int,int>>v;
        for(auto x:mp){
            v.push_back({x.second,x.first});
            // j++;
            // if(j==k) break;
        }
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--){
            ans.push_back(v[i].second);
            j++;
            if(j==k) break;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        
        vector<int>array(n);
        
        for(int i=0; i<n; i++)
            cin>>array[i];
            
        cin>>k;
        
        Solution obj;
        vector<int> result = obj.TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}  // } Driver Code Ends