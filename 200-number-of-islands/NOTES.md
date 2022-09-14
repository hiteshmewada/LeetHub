BFS
​
class Solution {
public:
int numIslands(vector<vector<char>>& grid) {
int n=grid.size(),m=grid[0].size();
vector<int>index={0,1,0,-1,0};
int ans=0;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(grid[i][j]=='1'){
ans++;
grid[i][j]='0';
queue<pair<int,int>>q;
q.push({i,j});
while(q.size()){
int row=q.front().first;
int col=q.front().second;
q.pop();
for(int del=0;del<4;del++){
int newr=row+index[del];
int newc=col+index[del+1];
if(newr>=0 and newr<n and newc>=0  and                                      newc<m and grid[newr][newc]=='1'){
q.push({newr,newc});
grid[newr][newc]='0';
}
}
}
}
}
}
return ans;
}
};