// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int dp[1001][1001];
int solve(vector<vector<int>>& m,int i,int j,int pre){
    if(i<0 or j<0 or i==m.size() or j==m[0].size() or pre>=m[i][j]) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int cur=m[i][j];
    return dp[i][j]=max({solve(m,i+1,j,cur),solve(m,i-1,j,cur),solve(m,i,j+1,cur),
        solve(m,i,j-1,cur)})+1;
}
    int longestIncreasingPath(vector<vector<int>>& m) {
        // Code here
        memset(dp,-1,sizeof(dp));
        int ans=INT_MIN;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                int temp=solve(m,i,j,0);
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends