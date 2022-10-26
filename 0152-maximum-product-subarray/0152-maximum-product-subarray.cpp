class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),left=nums[0],right=nums[0];
        int ans=1;
        bool zero=false;
        for(auto x:nums){
            ans*=x;
            if(ans==0){
                zero=true;
                ans=1;
                continue;
            }
            left=max(left,ans);
        }
        ans=1;
        for(int i=n-1;i>=0;i--){
             ans*=nums[i];
            if(ans==0){
                zero=true;
                ans=1;
                continue;
            }
            right=max(right,ans);
        }
        if(zero) return max(max(left,right),0);
        return max(left,right);
    }
};