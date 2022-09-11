class Solution {
public:
    bool checkBfs(vector<vector<int>>& graph, int cur, vector<int>&col){
        queue<int>q;
        q.push(cur);
        col[cur]=1;
        while(q.size()){
            int a=q.front();
            q.pop();
            for(auto x:graph[a]){
                if(col[x]==-1) {
                    col[x]=1-col[a];
                    q.push(x);
                }
                else if(col[x]==col[a]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!checkBfs(graph,i,col)) return false;
            }
        }
        return true;
    }
};