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
​
Optimised Space Dp in bottome up
​
class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) {
int first=cost[0],second=cost[1];
int n=cost.size();
if(n<2) return min(first,second);
for(int i=2;i<n;i++){
int cur=cost[i]+min(first,second);
first=second;
second=cur;
}
return min(first,second);
}
};