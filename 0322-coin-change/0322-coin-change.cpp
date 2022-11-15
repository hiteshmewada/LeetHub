class Solution {
public:

    int coinChange(vector<int>& c, int amt) {
        // sort(coins.begin(),coins.end());
        int n=c.size();
         int dp[n+1][amt+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=amt;i++) dp[0][i]=1e9;
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amt;j++){
                if(j-c[i-1]>=0)
               dp[i][j]=min(1+dp[i][j-c[i-1]],dp[i-1][j]);
                else dp[i][j]=dp[i-1][j];
            }
        }
        if(dp[n][amt]>=1e9) return -1;
       return  dp[n][amt];
    }
};