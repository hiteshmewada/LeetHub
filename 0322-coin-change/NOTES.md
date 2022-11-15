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