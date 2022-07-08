class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mp;
        for(auto x:nums2){
            while(st.size() and st.top()<x ){
                mp[st.top()]=x;
                st.pop();
            }
            st.push(x);
        }
        vector<int>ans;
        for(auto x:nums1){
            if(mp.find(x)!=mp.end()) ans.push_back(mp[x]);
            else ans.push_back(-1);
        }
        return ans;
    }
};