
class Solution {
public:
    vector<vector<int>>dp;
    bool solve(string s1,int i, string s2,int j, string s3,int k){
        if(i==s1.size()) return s2.substr(j)==s3.substr(k);
        if(j==s2.size()) return s1.substr(i)==s3.substr(k);
        if(dp[i][j]!=-1) return dp[i][j]==1?true:false;
        bool ans=false;
        if((s3[k]==s1[i] and solve(s1,i+1,s2,j,s3,k+1)) or (s3[k]==s2[j] and solve(s1,i,s2,j+1,s3,k+1))) ans=true;
        dp[i][j]=ans?1:0;
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        int n=s1.size(),m=s2.size();
        dp.resize(n);
        for(int i=0;i<n;i++) {dp[i].resize(m);for(int j=0;j<m;j++) dp[i][j]=-1;}
        return solve(s1,0,s2,0,s3,0);
    }
};