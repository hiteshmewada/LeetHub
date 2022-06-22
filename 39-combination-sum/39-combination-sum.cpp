class Solution {
public:
    void f(vector<int>& c,int i, int t,vector<vector<int>>&ans,vector<int>&v){
        if(i==c.size()){
            if(t==0) ans.push_back(v);
            return;
        }
        if(c[i]<=t){
            v.push_back(c[i]);
            f(c,i,t-c[i],ans,v);
            v.pop_back();
        }
        f(c,i+1,t,ans,v);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        f(candidates,0,target,ans,v);
        return ans;
    }
};