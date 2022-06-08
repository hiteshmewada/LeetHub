class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int ans=0;
        for(auto x:nums){
            st.insert(x);
        }
        for(auto x:nums){
            if(!st.count(x-1)){
                int cur=x,cnt=1;
                while(st.count(cur+1)){
                    cnt++;
                    cur++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};