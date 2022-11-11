class Solution {
public:
    int dp[501][501];
    int f(string w1, int i, string w2, int j){
       if(i<0){
           if(j<0) return 0;
           else return j+1;
       }
        else {
            if(j<0) return i+1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j])
            return dp[i][j]=f(w1,i-1,w2,j-1);
        
            int c1=1+f(w1,i-1,w2,j); // delete
            int c2=1+ f(w1,i,w2,j-1);  // insert
            int c3=1+ f(w1,i-1,w2,j-1); // replace
        
        return dp[i][j]=min({c1,c2,c3});
    }
    int minDistance(string w1, string w2) {
        int n=w1.size(),m=w2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int i=0;i<=m;i++) dp[0][i]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(w1[i-1]==w2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else{
                    int c1=1+dp[i-1][j]; // delete
                    int c2=1+ dp[i][j-1];  // insert
                    int c3=1+ dp[i-1][j-1]; // replace

                     dp[i][j]=min({c1,c2,c3});
                }
                    
            }
        }
        return dp[n][m];
        
    }
};