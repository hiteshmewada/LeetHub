// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int ans=-1;
int helper(vector<vector<int>>&v,vector<vector<int>>&dp,int x,int y){
    int n=v.size(),a=v[0].size();
    if(x>=n or y>=a or x<0 or y<0 or v[x][y]==-1) {
        // ans=max(ans,k);
        // cout<<x<<" "<<y<<endl;
        return 0;
    }
    if(dp[x][y]!=-1) {
         return dp[x][y];
    }
    int b=v[x][y],c=0,d=0,e=0;
    c=helper(v,dp,x+1,y);
    d=helper(v,dp,x+1,y+1);
    e=helper(v,dp,x+1,y-1);
    return dp[x][y]=max(c,max(d,e))+v[x][y];
}
int MaxGold(vector<vector<int>>&v){
    // Code here
    int n=v.size(),a=v[0].size(),c=0;
    vector<vector<int>>dp(n+1,vector<int>(a+1,-1));
    for(int i=0;i<a;i++){
        ans=max(ans,helper(v,dp,0,i));
        // cout<<ans<<endl;
    }
    return ans;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends