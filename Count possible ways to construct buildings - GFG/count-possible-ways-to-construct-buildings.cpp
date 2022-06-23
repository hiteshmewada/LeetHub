// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long long mod=1000000007;
	map<pair<long long,char>,long long>dp;
	bool check(string s){
	    for(int i=0;i<s.size()-1;i++){
	        if(s[i]==s[i+1] and s[i]=='B') return false;
	    }
	    return true;
	}
	int f(long long n,char c,int i){
	    if(i==n){
	        return dp[{i,c}]=1;
	    }
	    if(dp.find({i,c})!=dp.end()) return dp[{i,c}];
	    if(c=='B') return dp[{i,c}]=f(n,'S',i+1)%mod;
	    return dp[{i,c}]=(long long )((f(n,'B',i+1)%mod)+f(n,'C',i+1)%mod);
	}
	int TotalWays(int N)
	{
	    // Code here
	   // string s;
	   // memset(dp,-1,sizeof(dp));
	    long long ans=f(N,'B',1)%mod+f(N,'S',1)%mod;
	    ans%=mod;
	    ans*=ans;
	    return (int)(ans%mod);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends