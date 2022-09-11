Topological Sort
​
class Solution {
public:
bool canFinish(int n, vector<vector<int>>& pre) {
vector<vector<int>>adj(n,vector<int>());
vector<int>deg(n,0);
for(auto x:pre){
adj[x[1]].push_back(x[0]);
deg[x[0]]++;
}
queue<int>q;
for(int i=0;i<n;i++){
if(deg[i]==0) q.push(i);
}
while(q.size()){
int cur=q.front();n--;
q.pop();
for(auto x:adj[cur]){
if(--deg[x]==0) q.push(x);
}
}
return n==0;
}
};