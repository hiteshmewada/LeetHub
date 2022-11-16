class Solution {
public:
    // int f(int i, int j, vector<int>&v,vector<vector<int>>&dp){
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int  ans=1e9;
    //     for(int k=i;k<=j;k++){
    //         int temp=v[j+1]-v[i-1]+f(i,k-1,v,dp)+ f(k+1,j,v,dp);
    //         ans=min(ans,temp);
    //     }
    //     return dp[i][j]=ans;
    // }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
       int m=cuts.size()-2;
        vector<vector<int>>dp(m+2,vector<int>(m+2,0));
        for(int i=m;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(i>j) continue;
                int  ans=INT_MAX;
                for(int k=i;k<=j;k++){
                    int temp=cuts[j+1]-cuts[i-1]+dp[i][k-1]+ dp[k+1][j];
                    ans=min(ans,temp);
                }
                 dp[i][j]=ans;
            }
        }
        return dp[1][m];
    }
};