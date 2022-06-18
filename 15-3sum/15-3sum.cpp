class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int i=0;
        for(auto x:nums) {
            mp[x]=i;
            i++;
        }
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int req=-1*(nums[i]+nums[j]);
                if(mp.find(req)!=mp.end() and mp[req]>j){
                    vector<int>v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(req);
                    ans.push_back(v);
                }
                j=mp[nums[j]];
            }
            i=mp[nums[i]];
        }
        return ans;
    }
};