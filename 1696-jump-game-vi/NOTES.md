Failed recursive + memo
class Solution {
public:
int dp[100001];
int rec(vector<int>& nums, int k,int ind){
if(ind==nums.size()-1){
return nums[ind];
}
if(dp[ind]!=-1) return dp[ind];
int sum=INT_MIN;
int n=nums.size()-1, a=ind+k;
for(int i=ind+1;i<=min(a,n);i++){
sum=max(sum,rec(nums,k,i));
}
return dp[ind]=sum+nums[ind];
}
int maxResult(vector<int>& nums, int k) {
memset(dp,-1,sizeof(dp));
return rec(nums,k,0);
}
};
​
Failed Dp
​
class Solution {
public:
int maxResult(vector<int>& nums, int k) {
int n=nums.size();
vector<int>dp(n,INT_MIN);
dp[0]=nums[0];
for(int i=1;i<n;i++){
for(int j=1;j<=k and (i-j)>=0 ; j++){
dp[i]=max(dp[i],(dp[i-j]+nums[i]));
}
}
return dp.back();
}
};
​
​