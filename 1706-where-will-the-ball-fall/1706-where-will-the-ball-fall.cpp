class Solution {
public:
    vector<int>ans;
    int dp[101][101];
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid[0].size();
        ans.resize(n,0);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            ans[i]=findBallDrop(0,i,grid);
        }
        return ans;
    }
    int findBallDrop(int r, int c, vector<vector<int>>& grid){
        // base case
        if(r==grid.size()) return c;
        int nxtCol=c+grid[r][c];
        // if(dp[r][c]!=-1) return dp[r][c];
        if(nxtCol<0 or nxtCol>grid[0].size()-1 or grid[r][c]!=grid[r][nxtCol]) return -1;
        if(dp[r][c]!=-1) return dp[r][c];
        return dp[r][c]=findBallDrop(r+1,nxtCol,grid);
    }
};