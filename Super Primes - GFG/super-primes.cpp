// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int superPrimes(int n)
	{
	    // Your code goes here
	    int N=1000002;
	    bool prime[N];
	    memset(prime,true,sizeof(prime));
	    for(int i=2;i*i<=N;i++){
	        if(prime[i]){
	            for(int j=i*i;j<=N;j+=i) 
	                prime[j]=false;
	        }
	    }
	   // int pre[1e6+2]={0};
	    int ans=0;
	    for(int i=3;i<=n;i++){
	        if(prime[i]){
	           // cout<<i<<" "<<prime[i];
	            if(prime[i+2] and i+2<=n) ans++;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends