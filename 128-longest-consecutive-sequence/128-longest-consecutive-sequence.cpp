class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto x:nums) st.insert(x);
        int ans=0;
        for(auto x:nums){
            if(!st.count(x-1)){
                int y=x,temp=0;
                while(st.count(y)){
                    y++;temp++;
                }
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};