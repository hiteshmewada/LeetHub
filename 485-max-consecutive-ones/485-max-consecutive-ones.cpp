class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size(),mx=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(nums[i]==0) sum=0;
            mx=max(mx,sum);
        }
        return mx;
    }
};