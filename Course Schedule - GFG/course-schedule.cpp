// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        //code here
        
       vector<int>topsort;
       vector<int>indegree(n);
       vector<int>adj[n];
       queue<int>q;
       for(auto x:pre){
           adj[x[1]].push_back(x[0]);
           indegree[x[0]]++;
       }
       for(int i=0;i<n;i++){
           if(indegree[i]==0) q.push(i);
       }
       while(!q.empty()){
           int cur=q.front();
           q.pop();
           topsort.push_back(cur);
           for(auto x:adj[cur]){
               indegree[x]--;
               if(indegree[x]==0) q.push(x);
           }
       }
       if(topsort.size()==n) return topsort;
       return {};
    }
};

// { Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends