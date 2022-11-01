class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int dp[101][101];
        memset(dp,0,sizeof(dp));
        vector<int>ans;
        for(int i=m;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i==m){
                    dp[i][j]=j;
                    continue;
                }
                int col=j+grid[i][j];
                if(col<0 or col>=n or grid[i][j]!=grid[i][col]) 
                    dp[i][j]=-1;
                else dp[i][j]=dp[i+1][col];
                if(i==0)
                    ans.push_back(dp[i][j]);
            }
        }
        return ans;
    }
};