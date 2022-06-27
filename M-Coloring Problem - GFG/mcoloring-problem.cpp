// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool safe(int node,int col,int n,bool graph[101][101],int color[]){
    for(int j=0;j<n;j++){
        if(j!=node and graph[j][node]==1 and color[j]==col)  return false;
    }
    return true;
}
bool f(int node,bool graph[101][101], int m, int n,int color[]){
    if(node==n) return true;
    for(int i=1;i<=m;i++)
    {
        if(safe(node,i,n,graph,color)){
            color[node]=i;
            if(f(node+1,graph,m,n,color)) return true;
            color[node]=0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    // color.resize(n,0);
    int color[n]={0};
    return f(0,graph,m,n,color);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends