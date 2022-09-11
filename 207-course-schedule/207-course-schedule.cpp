class Solution {
public:
    bool isCycle(int cur, vector<int>adj[],vector<int>&vis ){
        if(vis[cur]==1) return true;
        if(vis[cur]==0){
            vis[cur]=1;
            for(auto x:adj[cur]){
                if(isCycle(x,adj,vis)) return true;
            }
        }
        vis[cur]=2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>adj[n];
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
        }
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(isCycle(i,adj,vis)) return false;
        }
        
        return true;
    }
};