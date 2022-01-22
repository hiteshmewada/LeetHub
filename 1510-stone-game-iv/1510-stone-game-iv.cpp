class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool>dp(n+1);
        // dp[0]=0;
        // dp[1]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sqrt(i);j++){
                // cout<<dp[i-j*j]<<" "<<i<<" "<<j<<endl;
                if(dp[i-j*j]==false){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};