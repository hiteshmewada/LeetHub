class Solution {
public:

    int coinChange(vector<int>& c, int amt) {
        // sort(coins.begin(),coins.end());
        int n=c.size();
         int dp[n+1][amt+1];
        memset(dp,0,sizeof(dp));
        vector<int>pre(amt+1,0);
        for(int i=0;i<=n;i++){
            vector<int>cur(amt+1,0);
            for(int j=0;j<=amt;j++){
                if(i==0) cur[j]=1e9;
                else if(j==0) cur[j]=0;
                else{
                    if(j-c[i-1]>=0)
                   cur[j]=min(1+cur[j-c[i-1]],pre[j]);
                    else cur[j]=pre[j];
                }
                
            }
            pre=cur;
        }
        if(pre[amt]>=1e9) return -1;
       return  pre[amt];
    }
};