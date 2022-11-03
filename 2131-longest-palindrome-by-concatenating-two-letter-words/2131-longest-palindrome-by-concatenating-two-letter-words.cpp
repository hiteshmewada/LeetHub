class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        int ans=0,rep=0;
        for(auto x:words){
            mp[x]++;
           swap(x[0],x[1]);
            if(x[0]==x[1] ){
                if(mp[x]>=2){
                    ans+=4;
                    mp[x]=0;
                    rep--;
                }
                else
                rep++;
                continue;
            }
            if(mp[x]){
                ans+=4;
                mp[x]--;
                swap(x[0],x[1]);
                mp[x]--;
            }
        }
        if(rep) ans+=2;
        return ans;
    }
};