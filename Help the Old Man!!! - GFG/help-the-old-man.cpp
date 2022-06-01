// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
// 1 3 2, 1 2 3, 2 3 1
class Solution{
public:
pair<int,int>p;
void fun(int n, int &s,int from ,int to,int aux){
    if(n==0) return;
    fun(n-1,s,from,aux,to);
    s--;
    if(s==0) {
        p.first=from;
        p.second=to;
        return;
    }
    fun(n-1,s,aux,to,from);
}
    vector<int> shiftPile(int N, int n){
        // code here
        fun(N,n,1,3,2);
        return {p.first,p.second};
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends