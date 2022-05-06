// { Driver Code Starts
#include <bits/stdc++.h>
 
using namespace std;
 

 // } Driver Code Ends
class Solution{
public:
/*
    1. make adjacency list of the given graph
    2. find all strongly connected components of the given graph
    3. then create a new graph in which consider all strongly 
    connected components  as single node (let say this graph as grrrr)
    4. find no. of nodes in grrrr having outdegree ==0 (let say this no. is x1)
    5. if x1>1 then ans is 0 
    6. if x1==0 then ans is also 0
    7. so ans exist only when x==1 and the ans is equal to 
    no. of nodes in scc with outdegee ==0 in graph grrrr
*/
//A strongly connected component is the portion of a directed graph 
// in which there is a path from each vertex to another vertex. 
// It is applicable only on a directed graph.
void make_graph(vector<vector<int>> &V, vector<int>*adj,vector<int>*trans){
    for(int i=0;i<V.size()-1;i++){
        adj[V[i][0]].push_back(V[i][1]);
        trans[V[i][1]].push_back(V[i][0]);
    }
    return;
}
void topo_dfs(int node,vector<int>*adj,vector<bool>&vis,stack<int>&st){
    vis[node]=true;
    for(auto x:adj[node]){
        if(!vis[x]) topo_dfs(x,adj,vis,st);
    }
    st.push(node);
    return;
}
void dfs(int node,vector<int>*adj,vector<bool>&vis,unordered_set<int>&sett ){
    vis[node]=true;
    sett.insert(node);
    for(auto x:adj[node]){
        if(!vis[x]) dfs(x,adj,vis,sett);
    }
    return;
}
int out_deg(unordered_set<int>sett,vector<int>*adj){
    int out=0;
    for(auto x:sett){
        for(auto y:adj[x]){
            if(sett.find(y)==sett.end()) out++;
        }
    }
    return out;
}
    int captainAmerica(int N, int M, vector<vector<int>> &V){
        // Code Here
        int out_0=0;
        int mx=INT_MIN;
        vector<int>adj[N+1];
        vector<bool> vis(N+1,false);
        stack<int>st;
        vector<int>trans[N+1];
        make_graph(V,adj,trans);
        for(int i=1;i<N+1;i++){
            if(!vis[i])
                topo_dfs(i,adj,vis,st);
        }
        for(int i=0;i<N+1;i++) vis[i]=false;
        while(!st.empty()){
            unordered_set<int>sett;
            if(!vis[st.top()]){
                dfs(st.top(),trans,vis,sett);
                if(out_deg(sett,adj)==0){
                    int sz=sett.size();
                    mx=max(mx,sz);
                    out_0++;
                }
            }
            st.pop();

        }
        if(out_0>1) return 0;
        return mx;
    } 
};

// { Driver Code Starts.
 

int main() {
    int t;cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m+1);
        for(int i=0;i<m;i++){
            int a, b;cin >> a >> b;
            v[i].push_back(a);
            v[i].push_back(b);
        }
        
        Solution obj;
        cout << obj.captainAmerica(n, m, v) << endl;
    }
 
}  // } Driver Code Ends