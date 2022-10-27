class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        // memset(dp,0,sizeof(dp));
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int pre=i-1;pre>=-1;pre--){
                int len=dp[i+1][pre+1];
                if(pre==-1 or nums[i]>nums[pre])
                    len=max(len,1+ dp[i+1][i+1]);
                dp[i][pre+1]=len;
            }
        }
        return dp[0][0];
    }
};