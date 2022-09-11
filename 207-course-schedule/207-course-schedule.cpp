class Solution {
public:
    bool isCycle(int cur,int par, vector<int>adj[],vector<int>&vis, vector<int>&dfsvis ){
       vis[cur]=1;
        dfsvis[cur]=1;
        for(auto x:adj[cur]){
            if(!vis[x]){
                if(isCycle(x,cur,adj,vis,dfsvis)) return true;
            }
            else if(dfsvis[x]) return true;
        }
        dfsvis[cur]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
        }
        vector<int>vis(n,0);
        vector<int>dfsvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])
            if(isCycle(i,-1,adj,vis,dfsvis)) return false;
        }
        
        return true;
    }
};