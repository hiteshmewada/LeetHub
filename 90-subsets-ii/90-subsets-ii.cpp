class Solution {
public:
    set<vector<int>>st;
    void f(vector<int>& nums,int i,vector<int> v){
        if(i==nums.size()) {
            sort(v.begin(),v.end());
            st.insert(v);
            return;
        }
        // st.insert(v);
        v.push_back(nums[i]);
         f(nums,i+1,v);
        v.pop_back();
        f(nums,i+1,v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>v;
        f(nums,0,v);
        vector<vector<int>> ans;
        for(auto x:st) ans.push_back(x);
        return ans;
    }
};