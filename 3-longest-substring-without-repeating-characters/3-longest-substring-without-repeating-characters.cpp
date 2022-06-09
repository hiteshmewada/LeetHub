class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int ans=0;
        vector<int>v(500,-1);
        int r=0,l=0;
        while(r<s.size()){
            if(v[s[r]]!=-1)
                l=max(v[s[r]]+1,l);
            v[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
        }
        
         return ans;
    }
   
};