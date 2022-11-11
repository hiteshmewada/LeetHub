//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int dp[1002][1002];
	int ans=0;
	int f(int ind,int pre,int arr[],int n){
	    if(ind==n) return 0;
	    int val=0;
	    if(pre!=-1 and dp[ind][pre]!=-1) {
	        return dp[ind][pre];
	    }
	    if(pre==-1 or arr[ind]>arr[pre]){
	        val=max(val,arr[ind]+f(ind+1,ind,arr,n));
	    }
	    val=max(val,f(ind+1,pre,arr,n));
	    ans=max(ans,val);
	    return dp[ind][pre]=val;
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    memset(dp,-1,sizeof(dp));
	     f(0,-1,arr,n);
	     return ans;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends