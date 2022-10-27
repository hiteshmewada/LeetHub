class Solution {
public:
    int n;
    int dp[2501][2501];
    int f(int i, int pre,vector<int>& nums){
        if(i==n) return 0;
        if(pre!=-1 and dp[i][pre]!=-1) return dp[i][pre];
        int len=0;
        if(pre==-1 or nums[i]>nums[pre])
            len=max(len,1+f(i+1,i,nums));
        len=max(len,f(i+1,pre,nums));
        if(pre==-1) return len;
        return dp[i][pre]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        return f(0,-1,nums);
    }
};