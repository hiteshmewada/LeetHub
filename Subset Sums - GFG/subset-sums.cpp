// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
vector<int>ans;
void helper(vector<int> v, int n,int i, int sum){
    if(i>=n) {
        ans.push_back(sum);
        return;
    }
    ans.push_back(sum);
    for(int j=i+1;j<=n;j++){
        helper(v,n,j,sum+v[j-1]);
    }
    // helper(v,n,i+1,v[i]);
}
    vector<int> subsetSums(vector<int> v, int n)
    {
        // Write Your Code here
        helper(v,n,0,0);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends