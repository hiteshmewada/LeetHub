// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int eulerPath(int N, vector<vector<int>> graph){
        // code here
        vector<int>degree(N,0);
        for(int i=0;i<N;i++){
            int cnt=0;
            for(int j=0;j<N;j++){
                if(graph[i][j]) cnt++;
            }
            degree[i]=cnt;
        }
        int ans=0;
        for(auto x:degree){
            if(x%2) ans++;
        }
        if(ans==0 or ans==2) return 1;
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j = 0;j < N;j++)
                cin>>graph[i][j];
        
        Solution ob;
        cout<<ob.eulerPath(N, graph)<<"\n";
    }
    return 0;
}  // } Driver Code Ends