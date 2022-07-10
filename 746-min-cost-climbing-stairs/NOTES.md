Top Down
​
class Solution {
public:
int dp[1001];
int rec(int i,vector<int>& cost){
if(i>=cost.size()) return 0;
if(i+1>cost.size() or i+2>cost.size()) return cost[i];
if(dp[i]!=-1) return dp[i];
return dp[i]=cost[i]+ min(rec(i+1,cost),rec(i+2,cost));
}
int minCostClimbingStairs(vector<int>& cost) {
memset(dp,-1,sizeof(dp));
return min(rec(0,cost),rec(1,cost));
}
};
​
Bottom Up
​
class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) {
int dp[1001]={-1};
int n=cost.size();
for(int i=0;i<n;i++){
if(i<2) dp[i]=cost[i];
else dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
}
return min(dp[n-1],dp[n-2]);
}
};