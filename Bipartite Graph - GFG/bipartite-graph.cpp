// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    //first deal with the scenario where graph is not connected
        // so for v vertices define the color as -1 initially
        vector<int> c(V);
        for(int i=0;i<V;i++)
        {
            c[i]=-1;
        }
        //now go through the problem of disconnected graph
        for(int i=0;i<V;i++)
        {
            if(c[i]==-1)
            {
                c[i]=1;
        
                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int u=q.front();
                    q.pop();
                    //checking self loop
                    for(int j:adj[u])
                    {
                        //if color is not assigned then do it
                        if(c[j]==-1)
                        {
                            c[j]=c[u]?0:1;
                            q.push(j);
                        }
                        else if(c[j]==c[u])
                            return false;
                    }
                    
                }
            }
                 
        }
        return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends