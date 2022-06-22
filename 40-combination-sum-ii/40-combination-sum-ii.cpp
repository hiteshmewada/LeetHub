class Solution {
public:
    void f(vector<int>& c,int i, int t,vector<int>&v,vector<vector<int>>& ans){
        if(t==0){
            ans.push_back(v);
            return;
        }
        for(int j=i;j<c.size();j++){
            if(j>i and c[j]==c[j-1]) continue;
            if(c[j]>t) break;
            v.push_back(c[j]);
            f(c,j+1,t-c[j],v,ans);
            v.pop_back();
        }
//         if(i>=c.size()){
//             return;
//         }
//         if(c[i]<=t){
            
//         }
//         f(c,i+1,t,v,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        f(candidates,0,target,v,ans);
        return ans;
    }
};