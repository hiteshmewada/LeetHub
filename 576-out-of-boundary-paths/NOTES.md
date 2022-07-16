Recursion
​
class Solution {
public:
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
if(startRow<0 or startRow>=m or startColumn<0 or startColumn>=n) return 1;
if(maxMove==0) return 0;
return (findPaths(m,n,maxMove-1,startRow+1,startColumn)+
findPaths(m,n,maxMove-1,startRow-1,startColumn)+
findPaths(m,n,maxMove-1,startRow,startColumn+1)+
findPaths(m,n,maxMove-1,startRow,startColumn-1));
}
};
​
Memo
​
class Solution {
public:
int dp[52][52][52];
int M=1000000007;
int solve(int m, int n, int maxMove, int startRow, int startColumn){
if(startRow<0 or startRow>=m or startColumn<0 or startColumn>=n)            return 1;
if(maxMove==0) return 0;
if(dp[startRow][startColumn][maxMove]!=-1)
return dp[startRow][startColumn][maxMove]%M;
return dp[startRow][startColumn][maxMove]=
((solve(m,n,maxMove-1,startRow+1,startColumn)%M+
solve(m,n,maxMove-1,startRow-1,startColumn)%M)%M+
(solve(m,n,maxMove-1,startRow,startColumn-1)%M+
solve(m,n,maxMove-1,startRow,startColumn+1)%M)%M)%M;
}
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
// vector<vector<vector<int>>>dp(startRow,vector<vector<int>>(startColumn,vector<int>(maxMove,-1)));
memset(dp,-1,sizeof(dp));
return solve(m,n,maxMove,startRow,startColumn);
}
};