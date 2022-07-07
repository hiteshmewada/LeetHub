
class Solution {
public:
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        int n=s1.size(),m=s2.size();
        bool dp[m+1];
        for(int i=0;i<=n;i++) 
        {
            // dp[i].resize(m+1);
            for(int j=0;j<=m;j++) {
                 if(i==0 and j==0) dp[j]=true;
                 else if(i==0){
                     dp[j]=(dp[j-1] and s2[j-1]==s3[i+j-1]);
                 }
                else if(j==0)
                    dp[j]=(dp[j] and s1[i-1]==s3[i+j-1]);
                else{
                    dp[j]=((dp[j-1] and s2[j-1]==s3[i+j-1]) or 
                              (dp[j] and s1[i-1]==s3[i+j-1]));
                }
            }
        }
        return dp[m];
    }
};