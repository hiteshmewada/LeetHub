// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        vector<pair<int,int>>v;
        for(int i=0;i<N;i++){
            v.push_back({A[i],B[i]});
        }
        sort(v.begin(),v.end(),[&](const pair<int,int>a,const pair<int,int>b){
             return a.second>b.second;
            // else return a.first<b.first;
        });
        int ans=0;
        for(auto x:v){
            if(T<=0) break;
            int a=x.first,b=x.second;
            if(a<=T){
                T-=a;
                ans+=a*b;
            }
            else{
                ans+=T*b;
                T=0;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends