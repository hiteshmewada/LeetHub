class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool>dp(n+1);
        // dp[0]=0;
        // dp[1]=1;
        for(int i=0;i<=n;i++){
            if(dp[i]) continue;
            for(int j=1;i+j*j<=n;j++){
                // cout<<dp[i-j*j]<<" "<<i<<" "<<j<<endl;
                dp[i+j*j]=true;
            }
        }
        return dp[n];
    }
};