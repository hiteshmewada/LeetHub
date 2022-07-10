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