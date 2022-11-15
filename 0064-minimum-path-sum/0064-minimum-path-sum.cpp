class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        // int dp[n][m];
        // memset(dp,0,sizeof(dp));
        vector<int>nxt(m,0);
        for(int i=n-1;i>=0;i--){
            vector<int>cur(m,0);
            for(int j=m-1;j>=0;j--){
                
                if(i==n-1 and j==m-1) cur[j]=grid[i][j];
                else{
                    int l=grid[i][j];
                    if(i+1>=n) l+=1e9;
                    else l+=nxt[j]; // req next row cur col
                    int r=grid[i][j];
                    if(j+1>=m) r+=1e9;
                    else r+=cur[j+1]; // req cur row and next col
                     cur[j]=min(l,r);
                }
            }
            nxt=cur;
        }
        return nxt[0];
    }
};