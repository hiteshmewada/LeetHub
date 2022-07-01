class Solution {
public:
    void kSelection(vector<pair<int,int>>&v, int st, int end, int k){
        if(st>=end) return;
        auto pv=v[end];
        int i=st,j=st;
        while(i<end){
            if(v[i].second>pv.second) swap(v[i++],v[j++]);
            else i++;
        }
        swap(v[j],v[end]);
        int num=j-st-1;
        if(num==k) return;
        else if(num<k) kSelection(v,j+1,end,k-num);
        else kSelection(v,st,j-1,k);
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        vector<pair<int,int>>v;
        for(auto x:nums) mp[x]++;
        for(auto x:mp) v.push_back({x.first,x.second});
        kSelection(v,0,v.size()-1,k);
        int i=0;
        while(k and i<v.size()){
            ans.push_back(v[i].first);
            k--;
            i++;
        }
        return ans;
    }
};