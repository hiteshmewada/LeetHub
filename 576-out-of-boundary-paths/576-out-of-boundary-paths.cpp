class Solution {
public:
    
    int M=1000000007;
    int findPaths(int m, int n, int N, int x, int y) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[x][y]=1;
        int cnt=0;
        for(int moves=1;moves<=N;moves++){
            vector<vector<int>>temp(m,vector<int>(n,0));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==m-1) cnt=(cnt+dp[i][j])%M;
                    if(j==n-1) cnt=(cnt+dp[i][j])%M;
                    if(i==0) cnt=(cnt+dp[i][j])%M;
                    if(j==0) cnt=(cnt+dp[i][j])%M;
                    temp[i][j]=(((i>0 ? dp[i-1][j] : 0) +                       (j>0 ? dp[i][j-1] : 0))%M + 
                    ((i<m-1 ? dp[i+1][j] : 0) +                                   (j<n-1 ? dp[i][j+1] : 0))%M
                    ) %M;
                }
            }
            dp=temp;
        }
        return cnt;
    }
};