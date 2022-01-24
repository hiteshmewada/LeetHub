// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void revers(vector<int> &arr, int i,int j){
        while(i<j)
        swap(arr[i++],arr[j--]);
    }
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int i=arr.size()-2,j;
        while(arr[i]>=arr[i+1] and i>=0) i--;
        if(i<0){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        for(j=N-1;j>i;j--)
            if(arr[j]>arr[i]) break;
            swap(arr[i],arr[j]);
            revers(arr,i+1,N-1);
            return arr;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends