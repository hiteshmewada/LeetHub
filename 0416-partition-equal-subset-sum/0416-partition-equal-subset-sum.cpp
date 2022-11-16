class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums) sum+=x;
        if(sum%2) return false;
        sum/=2;
        // int dp[n][sum+1];
        vector<int>pre(sum+1,-1);
        for(int i=0;i<n;i++){
            vector<int>cur(sum+1,-1);
            for(int j=0;j<=sum;j++){
                if(j==0) cur[j]=true;
                else if(i==0) cur[j]=(nums[0]==j);
                else{
                    bool take=false;
                    if(nums[i]<=j) take=pre[j-nums[i]];
                    bool notTake=pre[j];
                    cur[j]=(take or notTake);
                }
            }
            pre=cur;
        }
        return pre[sum];
    }
};