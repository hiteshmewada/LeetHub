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
	    vector<vector<int>>dp(n,vector<int>(9*n,-1));
	    return help(str,0,0,dp);
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