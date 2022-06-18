class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
       vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i==0 or (i>0 and nums[i]!=nums[i-1])){
                int lo=i+1,hi=n-1,sum=0-nums[i];
                while(lo<hi){
                    int temp=nums[lo]+nums[hi];
                    if(temp==sum){
                        vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[lo]);
                        v.push_back(nums[hi]);
                        ans.push_back(v);
                        while(lo+1<n and nums[lo]==nums[lo+1]) lo++;
                        while(hi-1>=0 and nums[hi]==nums[hi-1]) hi--;
                        lo++;hi--;
                    }
                    else if(temp>sum) hi--;
                    else lo++;
                }
            }
        }
        return ans;
    }
};