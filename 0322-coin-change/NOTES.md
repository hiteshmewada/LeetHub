class Solution {
public:
int dp[13][10005];
int f(vector<int>& c, int amt, int i){
if(amt<0 or i==0) return 1e9;
if(amt==0) return 0;
if(dp[i][amt]!=-1) return dp[i][amt];
int l=1e9,r=1e9;
if(c[i-1]<=amt) l=1+f(c,amt-c[i-1],i);
r=f(c,amt,i-1);
return dp[i][amt]=min(l,r);
}
int coinChange(vector<int>& coins, int amount) {
// sort(coins.begin(),coins.end());
memset(dp,-1,sizeof(dp));
int val=f(coins,amount,coins.size());
if(val>=1e9) return -1;
return val;
}
};
​
Tabulation
​
class Solution {
public:
​
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