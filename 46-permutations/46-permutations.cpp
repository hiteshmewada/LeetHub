class Solution {
public:
    vector<vector<int>>ans;
    void f( vector<int>& n,int i,vector<int>& freq,vector<int>& v){
        if(v.size()==n.size()) {
            ans.push_back(v);return;
        }
        for(int j=0;j<n.size();j++){
            if(!freq[j]){
                v.push_back(n[j]);
                freq[j]=1;
                f(n,i+1,freq,v);
                v.pop_back();
                freq[j]=0;
            }
//             swap(v[i],v[j]);
            
//             swap(v[i],v[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>v;
         vector<int>freq(nums.size(),0);
        f(nums,0,freq,v);
        return ans;
    }
};