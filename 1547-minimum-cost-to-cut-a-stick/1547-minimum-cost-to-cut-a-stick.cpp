class Solution {
public:
    int f(int i, int j, vector<int>&v,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int  ans=1e9;
        for(int k=i;k<=j;k++){
            int temp=v[j+1]-v[i-1]+f(i,k-1,v,dp)+ f(k+1,j,v,dp);
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
       int m=cuts.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return f(1,m-2, cuts,dp);
    }
};