len=max(len,1+ dp[i+1][i+1]);
dp[i][pre+1]=len;
}
}
return dp[0][0];
}
};
​
TC : O(N*N)  SC : O(N)*2
​
class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
int n=nums.size();
vector<int>next(n+1,0), cur(n+1,0);
for(int i=n-1;i>=0;i--){
for(int pre=i-1;pre>=-1;pre--){
int len=next[pre+1];
if(pre==-1 or nums[i]>nums[pre])
len=max(len,1+ next[i+1]);
cur[pre+1]=len;
}
next=cur;
}
return next[0];
}
};
Another Approach
​
class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
int n=nums.size();
vector<int>dp(n+1,1);
int ans=1;
for(int i=0;i<n;i++){
for(int pre=0;pre<i;pre++){
if(nums[pre]<nums[i]) dp[i]=max(dp[i],1+dp[pre]);
}
ans=max(ans,dp[i]);
}
return ans;
}
};
​