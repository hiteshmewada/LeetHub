// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    void fun(vector<int> arr, int n, int idx, vector<vector<int>>&res, 
    vector<int>&subset){
        res.push_back(subset);
        for(int i=idx;i<n;i++){
            subset.push_back(arr[i]);
            fun(arr,n,i+1,res,subset);
            subset.pop_back();
            while(i+1<n and arr[i]==arr[i+1]) i++;
        }
    }
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        // code here 
        vector<vector<int>>res;
        vector<int>subset;
        sort(arr.begin(),arr.end());
        fun(arr,n,0,res,subset);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends