class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),l=nums[0],r=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            int x=nums[i];
            int temp=max({x,l*x,r*x});
            l=min({x,l*x,r*x});
            r=temp;
            ans=max(ans,r);
        }
        return ans;
    }
};