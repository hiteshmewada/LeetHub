class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int ans=0;
        unordered_set<int>st;
        int l=0;
        for(int r=0;r<s.size();r++){
            if(st.find(s[r])!=st.end()){
                while(l<r and st.find(s[r])!=st.end()){
                    st.erase(s[l]);
                    l++;
                }
            }
            st.insert(s[r]);
            ans=max(ans,r-l+1);
        }
        
         return ans;
    }
   
};