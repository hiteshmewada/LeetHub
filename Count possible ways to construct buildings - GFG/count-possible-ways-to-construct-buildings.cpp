// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    // Code here
	    if(N==0) return 0;
	    if(N<3) return (N+1)*(N+1);
	    long long pre=3;
	    long long pre_pre=2;
	    long long ans=0;
	    long long mod=1e9+7;
	    for(int i=3;i<=N;i++){
	        ans=(pre+pre_pre)%mod;
	        pre_pre=pre;
	        pre=ans;
	    }
	    return ((ans%mod)*(ans%mod))%mod;
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