// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    vector<int> dp(amount+1,10001);
	   //now enter the value for dp[0]=0
	   dp[0]=0;
	   // it is based on three steps,
	   // 1. pick the current coin=>dp[j-nums[i]]+1, here +1 for picking this coin
	   // 2. dont pick the current coin=>dp[i] value remains same
	   // 3. minimum of both of them  
	   for(int i=0;i<nums.size();i++)
	   {
	       for(int j=1;j<=amount;j++)
	       {
	           if(nums[i]<=j)
	            dp[j]=min(dp[j],dp[j-nums[i]]+1);
	       }
	   }
	   if(dp[amount]>amount)
	    return -1;
	   return dp[amount]; 
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends