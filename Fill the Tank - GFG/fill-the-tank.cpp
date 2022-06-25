// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
vector<vector<int>>adj;
long long ans(int cur,int* &Cap, int &n, int par){
    long long res=Cap[cur-1],mx=0,child=0;
    for(auto x:adj[cur]){
        if(x==par) continue;
        child++;
        long long child_cap=ans(x,Cap,n,cur);
        if(child_cap==-1) return -1;
        mx=max(mx,child_cap);
    }
    res+=child*mx;
    return (res>1e18?-1:res);
}
    long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Cap){
       // Code here
       adj.resize(N+1);
       for(auto x:Edges){
           adj[x[0]].push_back(x[1]);
           adj[x[1]].push_back(x[0]);
       }
       return ans(S,Cap,N,-1);
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends