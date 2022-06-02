class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=2;i<=n;i++){
            vector<int>v,vec;
            if(ans.size()) vec=ans[ans.size()-1];
            
            v.push_back(1);
            for(int j=1;j<i-1;j++){
                v.push_back(vec[j]+vec[j-1]);
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};