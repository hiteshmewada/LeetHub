class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        vector<vector<int>>v(n+1);
        for(auto x:nums) mp[x]++;
        for(auto x:mp) v[x.second].push_back(x.first);
        for(int i=v.size()-1;i>=0;i--){
            for(auto y:v[i]) {
                ans.push_back(y);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};