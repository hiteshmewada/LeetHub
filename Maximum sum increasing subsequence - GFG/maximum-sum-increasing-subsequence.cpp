//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
// 	int dp[1002][1002];
// 	int ans=0;
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    
	    vector<int>next(n+1,0),cur(n+1,0);
	   // memset(dp,0,sizeof(dp));
	    for(int i=n-1;i>=0;i--){
	        for(int pre=i-1;pre>=-1;pre--){
	             int val=next[pre+1];
        	    if(pre==-1 or arr[i]>arr[pre]){
        	        val=max(val,arr[i]+next[i+1]);
        	    }
	            cur[pre+1]=val;
	        }
	        next=cur;
	    }
	     
	     return next[0];
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