// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
long long mod=1e9+7;
void multiply(vector<vector<long long>> &F,vector<vector<long long>> &M){
    long long x=F[0][0]*M[0][0]+F[0][1]*M[1][0];
        long long y=F[0][0]*M[0][1]+F[0][1]*M[1][1];
        long long z=F[1][0]*M[0][0]+F[1][1]*M[1][0];
        long long w=F[1][0]*M[0][1]+F[1][1]*M[1][1];
        F[0][0]=x%mod;
        F[0][1]=y%mod;
        F[1][0]=z%mod;
        F[1][1]=w%mod;
}
void power(vector<vector<long long>>&F,long long n){
    if(n==0 or n==1) return ;
        vector<vector<long long>>M={{1,1},{1,0}};
        power(F,n/2);
        multiply(F,F);
        if(n%2) multiply(F,M);
}
    int FindNthTerm(long long int n) {
        // Code here
        vector<vector<long long>>F={{1,1},{1,0}};
        if(n==0) return 0;
        power(F,n);
        return F[0][0]%mod;
    }
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int n;
		cin >> n;
		Solution obj;
		int ans = obj.FindNthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends