class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums) sum+=x;
        if(sum%2) return false;
        sum/=2;
        bitset<10001>dp(1); // dp[0]=1;
        for(auto x:nums) dp|= (dp<<x);
        return dp[sum];
    }
};