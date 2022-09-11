class Solution {
public:
    bool checkDfs(vector<vector<int>>& graph, int cur, vector<int>&col){
        if(col[cur]==-1) col[cur]=1;
        for(auto x:graph[cur]){
            if(col[x]==-1) {
                col[x]=1-col[cur];
                if(!checkDfs(graph,x,col)) return false;
            }
            else if(col[x]==col[cur]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!checkDfs(graph,i,col)) return false;
            }
        }
        return true;
    }
};