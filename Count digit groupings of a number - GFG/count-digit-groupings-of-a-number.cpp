// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int help(string s, int ind, int sum, vector<vector<int>>&dp){
	    if(ind==s.size()) return 1;
	    int cur_sum=0,ans=0;
	    if(dp[ind][sum]!=-1) return dp[ind][sum];
	    for(int i=ind;i<s.size();i++){
	        cur_sum+=s[i]-'0';
	        if(cur_sum>=sum) ans+=help(s,i+1,cur_sum,dp);
	    }
	    return dp[ind][sum]=ans;
	}
	int TotalCount(string str){
	    // Code here
	    int n=str.size();
	   // return help(str,0,0,dp);
	   int presum[105]={0};
	   for(int i=1;i<=n;i++) presum[i]=presum[i-1]+(str[i-1]-'0');
	    vector<vector<int>>dp(n+1,vector<int>(presum[n]+1,0));
	   // base case
	   for(int i=0;i<=presum[n];i++) dp[n][i]=1;
	   for(int i=n-1;i>=0;i--){
	       for(int j=presum[n];j>=0;j--){
	           // just copying the recurrence
	           int res=0;
	           for(int k=i;k<n;k++){
	               int sum=presum[k+1]-presum[i];
	               if(sum>=j) res+=dp[k+1][sum];
	           }
	           dp[i][j]=res;
	       }
	   }
	   return dp[0][0];
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends