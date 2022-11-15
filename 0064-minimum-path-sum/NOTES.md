class Solution {
public:
int dp[202][202];
int f(vector<vector<int>>& grid, int i, int j){
if(i==grid.size() or j==grid[0].size()) return 1e9;
if(i==grid.size()-1 and j==grid[0].size()-1) return grid[i][j];
if(dp[i][j]!=-1) return dp[i][j];
int l=grid[i][j] + f(grid,i+1,j);
int r=grid[i][j] + f(grid,i,j+1);
return dp[i][j]=min(l,r);
}
int minPathSum(vector<vector<int>>& grid) {
memset(dp,-1,sizeof(dp));
return f(grid,0,0);
}
};
​
Tabulation DP
​
class Solution {
public:
int minPathSum(vector<vector<int>>& grid) {
int n=grid.size(),m=grid[0].size();
int dp[n][m];
memset(dp,0,sizeof(dp));
for(int i=n-1;i>=0;i--){
for(int j=m-1;j>=0;j--){
if(i==n-1 and j==m-1) dp[i][j]=grid[i][j];
else{
int l=grid[i][j];
if(i+1>=n) l+=1e9;
else l+=dp[i+1][j];
int r=grid[i][j];
if(j+1>=m) r+=1e9;
else r+=dp[i][j+1];
dp[i][j]=min(l,r);
}
}
}
return dp[0][0];
}
};