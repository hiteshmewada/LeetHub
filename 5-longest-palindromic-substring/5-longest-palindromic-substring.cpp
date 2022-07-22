class Solution {
public:
    // babad   dabab
    // cbbd   dbbc
    // ac ca
    string longestPalindrome(string s) {
        string ans;
        int n=s.size();
        int st=0,end=n-1,len=-1;
        
        
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0) dp[i][j]=true;
                else if(gap==1){
                    dp[i][j]=(s[i]==s[j]);
                }
                else{
                    if(s[i]==s[j] and dp[i+1][j-1]) dp[i][j]=true;
                    else dp[i][j]=false;
                }
                if(dp[i][j]) {
                    if(gap>len){
                        len=gap;st=i;end=j;
                    }
                    
                }
            }
        }
        for(int i=st;i<=end;i++) ans+=s[i];
        return ans;
    }
};