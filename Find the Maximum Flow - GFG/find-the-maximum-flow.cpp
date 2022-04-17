// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
// you have to start from 1,1 and reach n,n and find sum of  min flow of all unique
// paths
int BFS(vector<vector<int>> &graph,vector<int>&parent,int src,int sink, int N){
    int min_cop=INT_MAX;
    fill(parent.begin(),parent.end(),-1);
    vector<bool>vis(N,false);
    queue<int>q;
    q.push(src);
    vis[src]=true;
    parent[src]=-1;
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(int v=0;v<N;v++){
            if(vis[v]==false and graph[u][v]!=0){
                if(v==sink){
                    parent[v]=u;
                    min_cop=min(min_cop,graph[u][v]);
                    return min_cop;
                }
                q.push(v);
                vis[v]=true;
                parent[v]=u;
                min_cop=min(min_cop,graph[u][v]);
            }
        }
    }
    return 0;
}
int fordFulkerson(vector<vector<int>> &graph,int src,int sink, int N){
    vector<int>parent(N);
    int res=0;
    while(BFS(graph,parent,src,sink,N)){
        int min_cop=BFS(graph,parent,src,sink,N);
        res+=min_cop;
        int v=sink;
        while(v!=src){
            int u=parent[v];
            graph[u][v]-=min_cop;
            graph[v][u]+=min_cop;
            v=parent[v];
        }
    }
    return res;
}
    int solve(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<vector<int>> graph;
        for(int i=0;i<N;i++){
            vector<int>v;
            for(int j=0;j<N;j++)
                v.push_back(0);
            graph.push_back(v);
        }
        for(auto x:Edges){
            int u=x[0]-1,v=x[1]-1,w=x[2];
            graph[u][v]+=w;
            graph[v][u]+=w;
        }
        return fordFulkerson(graph,0,N-1,N);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int i,j,N,M,u,v,w;
        int res;
        scanf("%d %d",&N,&M);
        vector<vector<int>> Edges; 
        for(i=0;i<M;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
        	Edges.push_back({u,v,w});
    	}
        Solution obj;
        res = obj.solve(N, M, Edges);
        cout<<res<<endl;
    }
    return 0;
}  // } Driver Code Ends